#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const long long  mod = 1000000007;



int main(){
  int n;
  cin >> n;

  string t ="MARCH";
  ll mp[5] = {0};
  rep(i,n){
    string s;
    cin >> s;
    rep(i,5){
      if(s[0] == t[i]) mp[i]++;
    }
  }

  ll ans = 0;
  rep(i,3){
    for(int j = i+1; j < 4; j++){
      for(int k = j+1; k < 5; k++){
        ans += mp[i]*mp[j]*mp[k];
      }
    }
  }
  cout << ans << endl;
}
