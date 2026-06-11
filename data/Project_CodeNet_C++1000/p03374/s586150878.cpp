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
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;



int main(){
    ll N;
    cin >> N;
    ll C;
    cin >> C;
    vector<ll> X(N,0);
    vector<ll> V(N,0);
    for(ll i=0;i<N;i++){
        cin>>X[i]>>V[i];
    ;}
    vector<ll> t(N,0);
    vector<ll> h(N,0);
    vector<ll> t2(N,0);
    vector<ll> h2(N,0);
    ll sum=0;
    for(ll i=0;i<N;i++){
        if(i==0)sum+=V[i]-2*X[i];
        else sum+=V[i]-2*X[i]+2*X[i-1];
        if(i==0)t[i]=max(sum,0LL);
        else t[i]=max(t[i-1],sum);
    ;}
    sum=0;
    for(ll i=N-1;i>=0;i--){
        if(i==N-1)sum+=V[i]-2*(C-X[i]);
        else sum+=V[i]+2*X[i]-2*X[i+1];
        if(i==N-1)h[i]=max(sum,0LL);
        else h[i]=max(h[i+1],sum);
    ;}
    sum=0;
    for(ll i=0;i<N;i++){
        if(i==0)sum+=V[i]-X[i];
        else sum+=V[i]-X[i]+X[i-1];
        if(i==0)t2[i]=max(sum,0LL);
        else t2[i]=max(t2[i-1],sum);
    ;}
    sum=0;
    for(ll i=N-1;i>=0;i--){
        if(i==N-1)sum+=V[i]-(C-X[i]);
        else sum+=V[i]+X[i]-X[i+1];
        if(i==N-1)h2[i]=max(sum,0LL);
        else h2[i]=max(h2[i+1],sum);
    ;}
    ll ans=0;
    chmax(ans,t2[N-1]);
    chmax(ans,h2[0]);
    for(ll i=1;i<=N-2;i++){
        chmax(ans,t[i]+h2[i+1]);
        chmax(ans,h[i]+t2[i-1]);
    ;}
    if(N>=2){
    chmax(ans,t[0]+h2[1]);
    chmax(ans,h[N-1]+t2[N-2]);
    }
    print(ans);
    return 0;
}
