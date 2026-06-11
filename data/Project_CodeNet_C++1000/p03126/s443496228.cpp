#include <bits/stdc++.h>

using namespace std;
 
//#define int long long
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define reps(i,n) for(ll i=0;i<=n;i++)

ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
 
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

ll modm(ll val, ll m) {
  ll res = val % m;
  if (res < 0) res += m;
  return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    ll n,m,k,a,ans=0;
    cin >> n >> m;
    vector<ll> s(m,0);
    rep(i,n){
      cin >> k;
      rep(j,k){
        cin >> a;
        a--;
        s[a]++;
      }
    }
    rep(c,m){
      if(s[c]==n){
        ans++;
      }
    }

    cout << ans << endl;
    return 0;
}
