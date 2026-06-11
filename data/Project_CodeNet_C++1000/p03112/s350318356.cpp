#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
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
    ll A;
    cin >> A;
    ll B;
    cin >> B;
    ll Q;
    cin >> Q;
    vector<ll> s(A+1,0);
    vector<ll> t(B+1,0);
    vector<ll> x(Q,0);
    for(ll i=0;i<A;i++){
        cin>>s[i+1]
    ;}
    for(ll i=0;i<B;i++){
        cin>>t[i+1]
    ;}
    for(ll i=0;i<Q;i++){
        cin>>x[i]
    ;}
    s[0]=-INF;
    t[0]=-INF;
    s.emplace_back(INF);
    t.emplace_back(INF);
    for(ll i=0;i<Q;i++){
        ll sl,tl,sr,tr;
        sr=*lower_bound(s.begin(), s.end(), x[i]);
        tr=*lower_bound(t.begin(), t.end(), x[i]);
        sl=*(upper_bound(s.begin(), s.end(), x[i])-1);
        tl=*(upper_bound(t.begin(), t.end(), x[i])-1);
        ll ans=INF;
        chmin(ans,x[i]-min(sl,tl));
        chmin(ans,max(sr,tr)-x[i]);
        chmin(ans,sr-tl+min(x[i]-tl,sr-x[i]));
        chmin(ans,tr-sl+min(x[i]-sl,tr-x[i]));
        print(ans);
    ;}

    
    return 0;
}
