#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,string>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

ll INF=99999999999999999;

int main(){
    ll ans=-INF;
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> A(N+1,0);
    vector<ll> B(N+1,0);
    vector<ll> C(N+1,0);
    for(ll i=1;i<=N;i++){
        cin>>A[i]>>B[i]>>C[i]
    ;}
    for(ll bit=0;bit<(1<<3);bit++){
        vector<ll> f(3,1);
        for(ll j=0;j<3;j++){
            if(bit&(1<<j))f[j]=-1
        ;}
        vector<ll> val(N,0);
        for(ll j=0;j<N;j++){
            val[j]=A[j+1]*f[0]+B[j+1]*f[1]+C[j+1]*f[2]
        ;}
        sort(val.begin(), val.end());
        reverse(val.begin(), val.end());
        ll sum=0;
        for(ll j=0;j<M;j++){
            sum+=val[j]
        ;}
        ans=max(ans,sum);
    ;}



  
  cout<<ans<<endl;

  
return 0;
}
