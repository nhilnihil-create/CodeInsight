#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s; cin >> s;
  ll ans;
  if(s[0]=='2') ans++;
  if(s[1]=='2') ans++;
  if(s[2]=='2') ans++;
  if(s[3]=='2') ans++;
  cout << ans << endl;
  return 0;
}