#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int now = 1;
  int cnt = 0;
  vector<int> streak;
  for (int i=0; i<n; i++) {
    if (s[i] == (char)('0' + now)) cnt++;
    else {
      streak.push_back(cnt);
      now = 1-now;
      cnt = 1;
    }
  }
  if (cnt != 0) streak.push_back(cnt);
  if (streak.size()%2 == 0) streak.push_back(0);
  vector<int> sum(streak.size()+1);
  for (int i=0; i<streak.size(); i++) {
    sum[i+1] = sum[i]+streak[i];
  }
  int width = 2*k +1;
  int ans = 0;
  for (int i=0; i<sum.size(); i+=2) {
    int left = i;
    int right = min(left+width, (int)(sum.size())-1);
    ans = max(ans, sum[right]-sum[left]);
  }
  cout << ans << endl;
}