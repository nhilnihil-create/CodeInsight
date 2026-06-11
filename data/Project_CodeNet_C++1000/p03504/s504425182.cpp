#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<v<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

//すべて半閉区間で扱う
struct cBIT {
  vector<ll> v;
  ll n;
  cBIT(ll n) : n(n), v(n) {}
  void add(ll i, ll x) {
    i++;
    while (i <= n) {
      v[i - 1] += x;
      i += i & -i;
    }
  }
  ll sum(ll i) {
    ll r = 0;
    while (i >= 1) {
      r += v[i - 1];
      i -= i & -i;
    }
    return r;
  }
  ll sum(ll l, ll r){
    if(l>=r)return 0;
    return sum(r)-sum(l);
  }
  ll get(ll i){return sum(i+1)-sum(i);}
};
 
struct BIT {
  cBIT p, q;
  BIT(ll n) : p(n + 1), q(n + 1) {}
  void add(ll l, ll r, ll w) {
    p.add(l, -w * l);
    p.add(r, w * r);
    q.add(l, w);
    q.add(r, -w);
  }
  ll sum(ll r) {
    return p.sum(r) + q.sum(r) * r;
  }
  ll sum(ll l, ll r){
    if(l>=r)return 0;
    return sum(r)-sum(l);
  }
  ll get(ll i){return sum(i+1)-sum(i);}
};
//↑すべて半閉区間で扱う

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll C;
    cin >> C;
    BIT tree(110000);
    vector<ll> s(N,0);
    vector<ll> t(N,0);
    vector<ll> c(N,0);
    vector<vector<P>> pro(31, vector<P>(0));
    for(ll i=0;i<N;++i){
        cin>>s[i]>>t[i]>>c[i];
        pro[c[i]].emplace_back(P(s[i],t[i]));
    }
    for(ll i=0;i<31;++i)sort(pro[i].begin(), pro[i].end());
    for(ll i=0;i<31;++i){
        for(ll j=0;j<pro[i].size();++j){
            if(j>0&&pro[i][j-1].second==pro[i][j].first)
                tree.add(pro[i][j].first+1,pro[i][j].second+1,1);
            else tree.add(pro[i][j].first,pro[i][j].second+1,1);
        }
    }
    ll ans=-INF;
    for(ll i=0;i<110000;++i){
        chmax(ans,tree.get(i));
    }
    prt(ans)
    return 0;
}
