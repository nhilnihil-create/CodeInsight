#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<double,ll>;
using um = unordered_map<ll,ll>;
#define fl cout<<flush;
#define endl '\n'
template <typename T> inline void prt(T v){cout<<v<<'\n';}
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;

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

inline ll mergecount(vector<ll> &a) {
  ll count = 0;
  ll n = a.size();
  if (n > 1) {
    vector<ll> b(a.begin(), a.begin() + n/2);
    vector<ll> c(a.begin() + n/2, a.end());
    count += mergecount(b);
    count += mergecount(c);
    for (ll i = 0, j = 0, k = 0; i < n; ++i)
      if (k == c.size())       a[i] = b[j++];
      else if (j == b.size())  a[i] = c[k++];
      else if (b[j] <= c[k])   a[i] = b[j++];
      else                   { a[i] = c[k++]; count += n/2 - j; }
  }
  return count;
}

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(N,0);
    for(ll i=0;i<N;++i)cin>>a[i];
    if(N==1){
        prt(a[0]);
        return 0;
    }
    ll L=0,R=1000000001;
    //中央値がx以上である区間の個数
    while(R-L>1){
        ll M=(L+R)/2;
        vector<ll> b(N,0);
        for(ll i=0;i<N;++i){if(a[i]>=M)b[i]=1;else b[i]=-1;}
        vector<ll> c(N+1,0);
        for(ll i=0;i<N;++i)c[i+1]=c[i]+b[i];
        ll count=N*(N+1)/2-mergecount(c);
        if(count<N*(N+1)/4)R=M;
        else L=M;
    }
    prt(L);fl
    return 0;
}

