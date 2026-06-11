
#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
//using namespace atcoder;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


#define debug(v) cout<<#v<<": ",prt(v);
template <typename A,typename B>
inline void prt(pair<A,B> p){cout<<"("<<p.first<<", "<<p.second<<")\n";}
template <typename A,typename B,typename C>
inline void prt(tuple<A,B,C> p){cout<<"("<<get<0>(p)<<", "<<get<1>(p)<<", "<<get<2>(p)<<")\n";}
inline void prt(bool p){if(p)cout<<"True"<<'\n';else cout<<"False"<<'\n';}
template <typename T> 
inline void prt(vector<T> v){cout<<'{';for(ll i=0;i<v.size();i++){cout<<v[i];if(i<v.size()-1)cout<<", ";}cout<<'}'<<'\n';}
template <typename T> 
inline void prt(deque<T> v){cout<<'{';for(ll i=0;i<v.size();i++){cout<<v[i];if(i<v.size()-1)cout<<", ";}cout<<'}'<<'\n';}
template <typename A,typename B>
inline void prt(map<A,B> v){cout<<'{';ll c=0;for(auto &p: v){cout<<p.first<<":"<<p.second;c++;if(c!=v.size())cout<<", ";}cout<<'}'<<'\n';}
template <typename A,typename B>
inline void prt(unordered_map<A,B> v){cout<<'{';ll c=0;for(auto &p: v){cout<<p.first<<":"<<p.second;c++;if(c!=v.size())cout<<", ";}cout<<'}'<<'\n';}
template <typename T> 
inline void prt(set<T> v){cout<<'{';for(auto i=v.begin();i!=v.end();i++){cout<<*i;if(i!=--v.end())cout<<", ";}cout<<'}'<<'\n';}
template <typename T> 
inline void prt(multiset<T> v){cout<<'{';for(auto i=v.begin();i!=v.end();i++){cout<<*i;if(i!=--v.end())cout<<", ";}cout<<'}'<<'\n';}

ll n;
vector<ll>a;

ll dp[100010][2];

int main(){
    cin >> n;
    a.resize(n);
    rep(i,n)cin>>a[i];
    rep(i,n)rep(j,2)dp[i][j]=-INF;
    dp[0][0]=a[0];
    
    for(int i=1;i<n;i++){
        //ひっくり返さない
        chmax(dp[i][0],dp[i-1][0]+a[i]);
        chmax(dp[i][0],dp[i-1][1]+a[i]);
        //ひっくり返す
        chmax(dp[i][1],dp[i-1][0]-a[i-1]*2-a[i]);
        chmax(dp[i][1],dp[i-1][1]+a[i-1]*2-a[i]);
    }
    ll ans = max(dp[n-1][1],dp[n-1][0]);
    cout << ans << endl;

    return 0;
}

