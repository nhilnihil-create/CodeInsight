#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
  int n, c;
  cin >> n >> c;
  vector<vector<int>> s(n, vector<int>(3)), channel(c, vector<int>(100005, 0));
  vector<int> record(100005, 0);
  for(int i = 0; i < n; i++) {
    cin >> s[i][0] >> s[i][1] >> s[i][2];
    s[i][0]--;
    s[i][2]--;
    channel[s[i][2]][s[i][0]]++;
    channel[s[i][2]][s[i][1]]--;
  }
  for(int i = 0; i < c; i++) {
    for(int j = 0; j < 100005; j++) {
      channel[i][j + 1] += channel[i][j];
    }
  }
  int ans = 0;
  for(int i = 0; i < 100001; i++) {
    int num = 0;
    for(int j = 0; j < c; j++) {
      if(channel[j][i] > 0) {
        num++;
      }
    }
    ans = max(ans, num);
  }
  cout << ans << endl;
  return 0;
}