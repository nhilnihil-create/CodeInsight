#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(n,0);
  for (int i = 1; i < n; i++) {
    if(s[i] == 'E') cnt[0]++;
  }
  int ans = cnt[0];
  for (int i = 1; i < n; i++) {
    if(s[i] == 'E' && s[i-1] == 'E') cnt[i] = cnt[i-1] - 1;
    else if((s[i] == 'E' && s[i-1] == 'W') || (s[i] == 'W' && s[i-1] == 'E')) cnt[i] = cnt[i-1];
    else cnt[i] = cnt[i-1] + 1;//s[i] == 'W' && s[i-1] == 'W'
    ans = min(ans, cnt[i]);
  }
  cout << ans;
}