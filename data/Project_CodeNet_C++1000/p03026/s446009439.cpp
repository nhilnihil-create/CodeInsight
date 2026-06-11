#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(N-1,0);
    vector<ll> b(N-1,0);
    for(ll i=0;i<N-1;++i){cin>>a[i]>>b[i];a[i]--;b[i]--;}
    vector<vector<ll>> G(N, vector<ll>(0));
    for(ll i=0;i<N-1;++i){
        G[a[i]].emplace_back(b[i]);
        G[b[i]].emplace_back(a[i]);
    }
    vector<ll> c(N,0);
    for(ll i=0;i<N;++i)cin>>c[i];
    sort(c.rbegin(), c.rend());
    vector<ll> vec(N,0);
    vector<ll> check(N,0);
    check[0]=1;
    queue<ll> que;
    que.emplace(0);
    ll now=0;
    while(!que.empty()){
        ll x=que.front();
        que.pop();
        vec[x]=c[now];
        now++;
        for(auto p: G[x]){
            if(!check[p]){
                check[p]=1;
                que.emplace(p);
            }
        }
    }
    ll sum=0;
    for(ll i=0;i<N;++i)sum+=c[i];
    prt(sum-c[0]);
    for(ll i=0;i<N;++i)cout<<vec[i]<<" ";cout<<endl;fl

    

    return 0;
}
