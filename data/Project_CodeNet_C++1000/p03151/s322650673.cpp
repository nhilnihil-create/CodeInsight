#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl;
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;



int main() {
  ll n; cin >> n;
  Vl a(n), b(n);
  ll sum_a = 0, sum_b = 0;
  ll ans = 0;
  rep(i, 0, n){
    cin >> a[i];
    sum_a += a[i];
  } 
  rep(i, 0, n){
    cin >> b[i];  
    sum_b += b[i];
  }
  if(sum_a < sum_b){
    cout << -1 << endl;
    return 0;
  }

  Vl v = {}; ll need = 0;
  rep(i, 0, n){
    if(a[i] < b[i]){ 
      ans++;
      need += b[i]-a[i];
    }
    if(a[i] > b[i]) v.push_back(a[i]-b[i]);
  }
  sort(ALL(v), greater<ll>());
  rep(i, 0, v.size()){
    if(need <= 0) break;
    ans++;
    need -= v[i];
  }
  cout << ans << endl;


  return 0;
}