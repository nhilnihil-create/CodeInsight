#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main() {
  string s; cin >> s;
  ll N = s.size();
  ll a[100001];
  ll ab[100001];
  ll abc[100001];
  ll tot[100001];
  a[0] = 0; ab[0] = 0; abc[0] = 0; tot[0] = 1;
  
  for (ll i = 1; i <= 1e5; i++) {
    if (s[i-1] == 'A') {
      a[i] = (a[i-1]+tot[i-1])%mod;
      ab[i] = ab[i-1];
      abc[i] = abc[i-1];
      tot[i] = tot[i-1];
    }
    if (s[i-1] == 'B') {
      a[i] = a[i-1];
      ab[i] = (a[i-1]+ab[i-1])%mod;
      abc[i] = abc[i-1];
      tot[i] = tot[i-1];
    }
    if (s[i-1] == 'C') {
      a[i] = a[i-1];
      ab[i] = ab[i-1];
      abc[i] = (ab[i-1]+abc[i-1])%mod;
      tot[i] = tot[i-1];
    }
    if (s[i-1] == '?') {
      a[i] = (3*a[i-1]%mod+tot[i-1])%mod;
      ab[i] = (3*ab[i-1]%mod+a[i-1])%mod;
      abc[i] = (3*abc[i-1]%mod+ab[i-1])%mod;
      tot[i] = tot[i-1]*3%mod;
    }
  }
  cout << abc[N] << endl;
}