#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
using namespace std;
typedef long long int lld;
typedef pair<int, int> pii;

const lld M = 1000000007;
const int MAXN = 200002;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int arr[n+1];
  for (int i = 1; i <= n; ++i) 
    cin >> arr[i];

  bool can = true;
  int ans[n+1];
  for (int i = n; i; --i) {
    int idx = -1;
    for (int j = 1; j <= i; ++j) {
      if (arr[j] == j) idx = j;
    }
    if (idx == -1) {
      can = false;
      break;
    }
    ans[i] = idx;
    for (int j = idx; j < i; ++j) {
      arr[j] = arr[j+1];
    }
  }
  if (can) {
    for (int i = 1; i <= n; ++i)
      cout << ans[i] << "\n";
  } else {
    cout << "-1\n";
  }
  return 0;
}