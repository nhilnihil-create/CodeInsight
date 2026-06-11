#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define PI 3.14159265358979323846
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define pll pair<long long, long long>
using namespace std;
using ll = long long;
using ld = long double;

// グローバル変数（入力）
ll n,h;
vll a,b;

void input() { 
  cin >> n >> h;
  a.resize(n);
  b.resize(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
}

ll solve() {
  sort(a.begin(),a.end(),greater<ll>());
  sort(b.begin(),b.end(),greater<ll>());
  ll ans=0;
  rep(i,n){
    if (b[i]>a[0]){
      ans++;
      if (h>b[i]){
        h-=b[i];
      } else {
        cout << ans << endl;
        return 0;
      }
    } 
  }
  cout << ans + (ll)ceil((ld)h/a[0]) << endl;
  return 0;
}

int main() {
  input();
  solve();
  return 0;
}
