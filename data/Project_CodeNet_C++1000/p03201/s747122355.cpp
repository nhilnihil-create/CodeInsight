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

int main(){
    ll N; cin >> N;
    vl a(N);rdv(a);
    ll ans = 0;
    vector<bool> used(N,false);
    for(ll num = 1LL<<33 ; 1<num ; num>>=1){
        unordered_map<ll,ll> md;// a[i]%num,そのようになる個数
        unordered_multimap<ll,ll> list;// a[i]%num、それを満たすlist
        rep(i,N){
            if (used[i] || num<=a[i]) continue;
            md[a[i] % num]++;
            list.emplace(a[i] % num,i);
        }
        eachdo(md,e){
            if(num/2<e.first) continue;
            if(!md.count(num - e.first)) continue;
            if(e.first!=num - e.first){
                ll tm = min(e.second,md[num - e.first]);
                ans += tm;
                ll cnt = 0;
                auto p = list.equal_range(e.first);
                for(auto it = p.first; it != p.second ; ++it){
                    if (cnt>=tm) break;
                    used[it->second] = true;
                    cnt++;
                }
                cnt = 0;
                auto q = list.equal_range(num - e.first);
                for(auto it = q.first; it != q.second ; ++it){
                    if (cnt>=tm) break;
                    used[it->second] = true;
                    cnt++;
                }
            }else{
                ll tm = e.second/2;
                ans += tm;
                ll cnt = 0;
                auto p = list.equal_range(e.first);
                for(auto it = p.first; it != p.second ; ++it){
                    if (cnt>=tm*2) break;
                    used[it->second] = true;
                    cnt++;
                }
            }
        }
        // rep(i,N) cout << used[i] ? 1 : 0;
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}