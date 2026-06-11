#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >>s;
  int cnt1=0, cnt0=0;
  rep(i,s.size()){
    if(s[i]=='0') cnt0++;
    if(s[i]=='1') cnt1++;
  }
  int ans = 2*min(cnt0, cnt1);
  cout << ans << endl;
  return 0;
}
