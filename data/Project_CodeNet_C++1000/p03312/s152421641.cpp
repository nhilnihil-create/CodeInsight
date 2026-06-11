#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl
#define first(v) get<0>(v)
#define second(v) get<1>(v)
#define third(v) get<2>(v)
template <typename T> bool chmax(T &a, T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    for(ll i=0;i<N;i++){
        cin>>A[i]
    ;}
    vector<ll> sumuntil(N,0);
    vector<ll> sumikou(N,0);
    ll sum=0;
    for(ll i=0;i<N;i++){
        sum+=A[i];
        sumuntil[i]=sum;
    ;}
    sum=0;
    for(ll i=N-1;i>=0;i--){
        sum+=A[i];
        sumikou[i]=sum;
    ;}
    vector<P> izen(N),ikou(N);
    //尺取り法
    ll mark=0;
    for(ll i=1;i<N;i++){
        ll h=sumuntil[i];
        izen[i]=P(max(h-sumuntil[mark],sumuntil[mark]),min(h-sumuntil[mark],sumuntil[mark]));
        while(mark<i-1&&abs(h-2*sumuntil[mark+1])<abs(h-2*sumuntil[mark])){
            mark++;
            izen[i]=P(max(h-sumuntil[mark],sumuntil[mark]),min(h-sumuntil[mark],sumuntil[mark]));
        }
    ;}
    mark=N-1;
    for(ll i=N-2;i>=0;i--){
        ll h=sumikou[i];
        ikou[i]=P(max(h-sumikou[mark],sumikou[mark]),min(h-sumikou[mark],sumikou[mark]));
        while(mark>i+1&&abs(h-2*sumikou[mark-1])<abs(h-2*sumikou[mark])){
            mark--;
            ikou[i]=P(max(h-sumikou[mark],sumikou[mark]),min(h-sumikou[mark],sumikou[mark]));
        }
    }
    ll ans=INF;
    for(ll i=1;i<=N-3;i++){
        ll h=max(izen[i].first,ikou[i+1].first)-min(izen[i].second,ikou[i+1].second);
        chmin(ans,h);
    ;}
    print(ans);

    return 0;
}
