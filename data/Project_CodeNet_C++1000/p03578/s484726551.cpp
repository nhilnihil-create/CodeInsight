#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;



int main() {
  ll n; cin >> n;
  map<ll, ll> ma;
  rep(i, 0, n){
    ll d; cin >> d;
    ma[d]++;
  }
  ll m; cin >> m;
  bool f = false;
  rep(i, 0, m){
    ll t; cin >> t;
    if(ma[t] > 0){
      ma[t]--;
      continue;
    }
    f = true;
  }
  if(f) cout << "NO" << endl;
  else cout << "YES" << endl;

  return 0;
}
