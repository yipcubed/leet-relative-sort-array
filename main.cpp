#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

// https://leetcode.com/problems/relative-sort-array/

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, int> m;
    for (int i = 0; i < arr2.size(); ++i) {
      m[arr2[i]] = arr2.size() - i;
    }
    sort(arr1.begin(), arr1.end(),
         [&m](int x, int y) -> bool {
           return (m[x] > m[y]) ||
               ((m[x] == 0) && (m[y] == 0) && y > x);
         });
    return arr1;
  }
};

void test1() {
  vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};

  vector<vector<int>> v2{
      vector<int>{0, 1, 0, 0},
      vector<int>{1, 1, 1, 0},
      vector<int>{0, 1, 0, 0},
      vector<int>{1, 1, 0, 0}
  };
  vector<int> arr1{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
  vector<int> arr2{2, 1, 4, 3, 9, 6};

  cout << "[2,2,2,1,4,3,3,9,6,7,19] ? \n" << Solution().relativeSortArray(arr1, arr2) << endl;

  vector<int> a1{28, 6, 22, 8, 44, 17};
  vector<int> a2{22, 28, 8, 6};

  cout << "[[22,28,8,6,17,44]] ? \n" << Solution().relativeSortArray(a1, a2) << endl;

}

void test2() {

}

void test3() {

}