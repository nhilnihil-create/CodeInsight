#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main(){
  int n;
  string s;
  cin >> n >> s;
  vector<int> vec(26);
  for(int i=0; i<n; ++i){
    ++vec[s[i]-'a'];
  }
  ll ans = 1;
  for(int i=0; i<26; ++i){
    if(vec[i] == 0)continue;
    ans *= vec[i] + 1;
    ans %= MOD;
  }
  --ans;
  if(ans < 0) ans += MOD;
  cout << ans << endl;
}