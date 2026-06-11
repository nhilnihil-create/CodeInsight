#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;



int main(){
  ll N;
  cin >> N;
  vector<ll> A(N,0);
  vector<ll> B(N,0);
  for(ll i=0;i<N;i++){
    cin>>A[i]>>B[i]
  ;}
  priority_queue<P>  fora;
  priority_queue<P>  forb;
  for(ll i=0;i<N;i++){
    fora.push(P(A[i]+B[i],i));
    forb.push(P(B[i]+A[i],i));
  ;}

  //    食ったら１
  vector<ll> check(N,0);
  ll ans=0;
  while(1){
    //Aの番
    while(1){
    if(fora.empty()){cout<<ans<<endl;return 0;};
    P x=fora.top();fora.pop();
    if(check[x.second]){continue;}
    else {
      ans+=A[x.second];check[x.second]++;break;
    }
    }
    //Bの番
    while(1){
    if(forb.empty()){cout<<ans<<endl;return 0;};
    P x=forb.top();forb.pop();
    if(check[x.second]){continue;}
    else {
      ans-=B[x.second];check[x.second]++;break;
    }
    }
    
  }
    
    return 0;
}
