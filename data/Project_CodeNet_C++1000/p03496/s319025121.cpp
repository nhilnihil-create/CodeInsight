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


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(N,0);
    for(ll i=0;i<N;++i)cin>>a[i];
    ll Max=-INF,Min=INF;
    ll wMax,wMin;
    for(ll i=0;i<N;++i){
        if(chmax(Max,a[i]))wMax=i;
        if(chmin(Min,a[i]))wMin=i;
    }
    if(Min>=0){
        prt(N-1)
        for(ll i=0;i<N-1;++i)cout<<i+1<<" "<<i+2<<endl;
    }
    else if(Max<=0){
        prt(N-1)
        for(ll i=N-2;i>=0;--i)cout<<i+2<<" "<<i+1<<endl;
    }
    else if(Min+Max>=0){
        prt(2*N-2)
        for(ll i=0;i<N;++i)if(i!=wMax)cout<<wMax+1<<" "<<i+1<<endl;
        for(ll i=0;i<N-1;++i)cout<<i+1<<" "<<i+2<<endl;
    }
    else{
        prt(2*N-2)
        for(ll i=0;i<N;++i)if(i!=wMin)cout<<wMin+1<<" "<<i+1<<endl;
        for(ll i=N-2;i>=0;--i)cout<<i+2<<" "<<i+1<<endl;
        cout<<endl;
    }
    
    return 0;
}
