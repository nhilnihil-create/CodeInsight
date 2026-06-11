#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  string s;
  ll k;
  cin >> s >> k;
  char ans = '1';
  if(k == 1) cout << s[0] << endl;
  else{
    int n = s.size();
    rep(i, n){
      if(k == i) break;
      if(s[i] == '1') continue;
      ans = s[i];
      break;
    }
    cout << ans << endl;
  }
       

  return 0;
}
