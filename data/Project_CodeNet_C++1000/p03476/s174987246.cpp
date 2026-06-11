#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)

signed main() {
  int q; cin >> q;
  int n = 100000; 
  vector<bool> is_prime(n+1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for(int i=2; i<=n; i++) 
    if(is_prime[i]) 
      for(int j = 2; i * j <= n; j++) 
        is_prime[i*j] = false;

  vector<int> c(n+1);
  rep(i,n) {
    c[i] += is_prime[i] && is_prime[(i+1)/2];
    c[i+1] += c[i];
  }

  rep(i,q) {
    int l,r; cin >> l >> r;
    cout << c[r] - c[l-1] << endl;
  }
}
