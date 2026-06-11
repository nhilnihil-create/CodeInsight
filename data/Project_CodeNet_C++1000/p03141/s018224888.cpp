#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
自分にとって最大をとるだけじゃだめ、妨害も考慮
ただ総合値が大きいのをとればいいんじゃ
*/
int main(){
  ll N; cin>>N;
  vector<vector<ll>> S(N,vector<ll>(3,0));
  for(ll i=0; i<N; i++){
    ll a,b; cin>>a>>b;
    S[i][0]=a;
    S[i][1]=b;
    S[i][2]=a+b;
  }
  sort(S.begin(), S.end(), [](auto& x, auto& y){return x[2] > y[2];});
  ll asum=0,bsum=0;
  for(ll i=0; i<N; i++){
    if(i%2==0) asum+=S[i][0];
    else bsum+=S[i][1];
  }
  cout<<asum-bsum<<endl;
}