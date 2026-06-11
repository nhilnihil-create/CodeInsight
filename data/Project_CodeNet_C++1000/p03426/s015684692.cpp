#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
struct edge{ll to,cost;};
const int inf = 1<<28;
const ll INF = 1LL<<53;
const int COMBMAX = 500005;
const ll MOD = 1e9+7;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;++i)
#define repf(i,n) for(int i=0;i<=n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define eachdo(v, e) for(const auto& e : v)
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (ll)distance(v.begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (ll)distance(v.begin(), upper_bound((v).begin(), (v).end(), e))
ll mpow(ll a, ll n,ll mod=MOD){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
template<class T1, class T2> ll bcount(T1 v, T2 a){return upper_index(v,a)-lower_index(v,a);} 
template<class T> bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
template<class T> void debug2(T v){rep(i,v.size()){rep(j,v[i].size())cout<<v[i][j]<<" ";cout<<endl;}}
template<class T> void rdv(T &v){rep(i,v.size())cin>>v[i];}
template<class T> void rdvv(T &v){rep(i,v.size()){rep(j,v[i].size())cin>>v[i][j];}}
// multimap
// mmap.emplace(key,value);
// auto ngw = list.equal_range("");
// for(auto e = ngw.first; it != ngw.second ; ++e)


int main(){
    ll H,W,D; cin >> H >> W >> D;
    ll lw = (H*W+D-1)/D;
    vector<vector<pair<ll,ll>>> list(D,vector<pair<ll,ll>>(lw));
    rep(i,H){
        rep(j,W){
            ll a; cin >> a;
            --a;
            list[a%D][a/D] = make_pair(i,j);
        }
    }
    vvl d(D,vl(lw+1,0));
    rep(i,D){
        rep(j,lw-1){
            d[i][j+2] = d[i][j+1] + abs(list[i][j+1].first - list[i][j].first) + abs(list[i][j+1].second - list[i][j].second);
        }
    }
    ll Q; cin >> Q;
    rep(i,Q){
        ll a,b; cin >> a >> b;
        --a;--b;
        cout << d[b%D][(b/D)+1] - d[a%D][a/D+1] << endl; 
    }
    // debug2(d);

    return 0;
}