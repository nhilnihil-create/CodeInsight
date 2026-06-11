
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
  cin >> s;
  int ans = 0;
  int n = s.size();
  if(n == 1) cout << ans << endl;
  else{
    for(int i = 1; i < n; i++){
      if(s[i - 1] == s[i]){
        ans++;
        if(s[i] == '1') s[i] = '0';
        else s[i] = '1';
      }
    }
    cout << ans << endl;
  }

  return 0;
}