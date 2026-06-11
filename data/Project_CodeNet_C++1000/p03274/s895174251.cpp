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
using Graph = vector<vector<int>>;


int main() {
  ll n, k; cin >> n >> k;
  Vl x(n);
  rep(i, 0, n) cin >> x[i];
  ll l, r;
  ll ans = INF;
  Rep(i, 0, n-k){
    l = x[i], r = x[i+k-1];
    if(r <= 0){
      ans = min(ans, abs(l));
    }else if(l >= 0){
      ans = min(ans, r);
    }else{ //0をまたぐとき
      ans = min({ans, r*2 + abs(l), 2*abs(l) + r});
    }
  }
  cout << ans << endl;

  return 0;
}
