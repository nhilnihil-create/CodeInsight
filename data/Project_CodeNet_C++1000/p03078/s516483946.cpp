#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
using Tu = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll X;
    cin >> X;
    ll Y;
    cin >> Y;
    ll Z;
    cin >> Z;
    ll K;
    cin >> K;
    vector<ll> A(X,0);
    vector<ll> B(Y,0);
    vector<ll> C(Z,0);
    for(ll i=0;i<X;i++){
        cin>>A[i]
    ;}
    for(ll i=0;i<Y;i++){
        cin>>B[i]
    ;}
    for(ll i=0;i<Z;i++){
        cin>>C[i]
    ;}
    vector<ll> AB(0);
    for(ll i=0;i<X;i++){
        for(ll j=0;j<Y;j++){
            AB.emplace_back(A[i]+B[j]);
        ;}
    ;}
    sort(AB.rbegin(), AB.rend());
    vector<ll> ans(0);
    ll o=min(X*Y,K);
    for(ll i=0;i<o;i++){
     for(ll j=0;j<Z;j++){
         ans.emplace_back(AB[i]+C[j]);
     ;}
    ;}
    sort(ans.rbegin(), ans.rend());
    for(ll i=0;i<K;i++){
        cout<<ans[i]<<endl;
    ;}

    return 0;
}
