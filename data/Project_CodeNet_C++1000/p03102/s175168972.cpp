#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main(){
  int n,m,c;
  cin >> n >> m >> c;
  vector<ll> b(m);
  rep(i,m) cin >> b[i];
  
  int ans = 0;
  rep(i,n){
    vector<ll> a(m);
    rep(j,m) cin >> a[j];
    int sum = 0;
    rep(k,m) sum += b[k]*a[k];
    if(sum+c>0) ans++;
  }
  
  cout << ans << endl;
}