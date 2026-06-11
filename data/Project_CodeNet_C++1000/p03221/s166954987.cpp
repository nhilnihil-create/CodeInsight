#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec                vector<int>
#define vecll              vector<ll>
#define vecd               vector<double>
#define vecst              vector<string>
#define vecb               vector<bool>
#define vec2(var, n, m)    vector<vector<int>> var(n, vector<int>(m, 0))
#define vecll2(var, n, m)  vector<vector<ll>> var(n, vector<ll>(m, 0))

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vecst var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());
#define f_sum(var)       accumulate(all(var), 0)
#define f_sumll(var)     accumulate(all(var), 0LL)
#define chmin(v1, v2)    v1 = min(v1, v2)
#define chmax(v1, v2)    v1 = max(v1, v2)
#define pb(var)          push_back(var)
#define prt(var)         cout << (var) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
void prtok(bool ok){prt(ok ? "Yes" : "No");}
//----------------------------------------------------------------

int main(void) {
  ll n, m;
  cin >> n >> m;
  vecll p(m), y(m);
  vector<vector<ll>> country(n+1);

  rep(i,m){
    cin >> p[i] >> y[i];
    country[p[i]].pb(y[i]);
  }

  rep(i,n+1){
    sortall(country[i]);
  }

  rep(i,m){
    ll tmp=0;
    tmp += 1000000*p[i];
    auto k = lower_bound(all(country[p[i]]), y[i]);
    tmp += k - country[p[i]].begin() + 1;
    prtfill(12, tmp);
    cout << "\n";
  }
}
