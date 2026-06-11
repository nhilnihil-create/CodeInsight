#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {
  string s;
  cin >> s;
  rep(bit,(1<<3)){
    ll sum = s[0]-'0';
    string ans= "";
    ans += s[0];
    rep(i,3){
      if (bit & (1<<i)) {
        sum += s[i+1]-'0';
        ans += "+" + s.substr(i+1,1);
      } else {
        sum -= s[i+1]-'0';
        ans += "-" + s.substr(i+1,1);
      }
    }
    if(sum == 7){
      cout << ans <<  "=7" << endl;
  		return 0;
    } 
  }
  return 0;
}
