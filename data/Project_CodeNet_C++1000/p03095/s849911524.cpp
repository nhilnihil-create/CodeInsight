# include <iostream>
# include <cstring>

using namespace std;
const int mod = 1e9 + 7;
# define ll long long

ll mul(ll a, ll b){
  return ((a%mod) * (b%mod)) % mod;
}

int main(){

  int n;
  cin >> n;
  string s;
  cin >> s;

  int occ[26];
  memset(occ, 0, sizeof(occ));
  for(char c : s) occ[c-'a']++;
  
  ll ans = 1;
  for(char c='a'; c<='z'; c++){
    ans = mul(ans, occ[c-'a']+1);
  }

  ans = (ans + mod - 1) % mod;
  cout << ans << endl;
  return 0;
}