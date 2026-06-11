#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  multiset<ll> se;
  for(ll i=0;i<n;i++){
    ll a; cin >>a; se.insert(a);
  }
  ll ans=0;
  while(se.size()){
    ll num = *se.rbegin();
    se.erase(se.find(num));
    ll t=1;
    while(t<=num)t*=2;
    if(se.count(t-num)){
      se.erase(se.find(t-num));
      ans++;
    }
  }
  cout<<ans<<endl;
}