#include <iostream>
using namespace std;

# define ll long long

int frequency[26];

const int mod = 1e9 + 7;
ll kali(ll a, ll b){
  return ((a%mod) * (b%mod)) % mod;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  for(int i=0; i<s.size(); i++){
    frequency[s[i] - 'a']++;
  }

  ll ans = 1;
  for(int i=0; i<26; i++){
    ans = kali(ans, frequency[i]+1);
  }

  ans = (ans - 1 + mod) % mod;
  cout << ans << endl;
}