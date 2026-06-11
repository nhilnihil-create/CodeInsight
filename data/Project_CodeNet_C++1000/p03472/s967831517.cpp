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

ll solve(const ll &N,ll H,const vl &a,const vl &b){
    priority_queue<P> pq;
    for(ll i=0;i<N;++i){
        pq.emplace(P(a[i],INF));
        pq.emplace(P(b[i],1));
    }
    ll ans=0;
    while(H>0){
        P x=pq.top();
        if(x.second==1){
            pq.pop();
            H-=x.first;
            ans++;
        }
        else{
            ll num=(H+x.first-1)/x.first;
            ans+=num;
            H=0;
        }
    }
    return ans;
}

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll H;
    cin >> H;
    vector<ll> a(N,0);
    vector<ll> b(N,0);
    for(ll i=0;i<N;++i)cin>>a[i]>>b[i];
    
    prt(solve(N,H,a,b))

    return 0;
}
