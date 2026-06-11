#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  //XORってなんだ
  //1,6,3
  //001
  //110
  //011
  //-----
  //100が最大
  //各桁の0の数調べて、半分未満なら1、半分以上なら0を選べばOKっぽ
  //10^5くらいならX決定後に再計算しても間に合いそうな気がする
//4=      100
//100=1100100
//123=1111011
//    1100011=99次点
//ベストと比較。K=0,X=1だった箇所は、X=0にする。
//K=1,X=0があらわれたら、そこ以降はXのまま
  ll N,K,X=0;
  cin>>N>>K;
  ll k=K, a=0;
  while(k>0){
    k/=2;
    a++;
  }
  vector<ll>Z(a,0);
  vector<ll>Y(N,0);
  for(int i=0; i<N; i++){
    ll A,j=a-1;
    cin>>A;
    Y[i]=A;
    while(A>0 && j>=0){
      if(A%2==1)
        Z[j]++;
      A/=2;
      j--;
    }
  }
  //bestXつくる
  vector<ll>Xs(a,0);  
  for(int i=0; i<a; i++){
    X*=2;
    if(Z[i]<(N+1)/2){
      X++;
      Xs[i]++;
    }
  }
  //Kにあわせる
  if(X>K){
    ll k=K, j=a-1;
    X=0;
    vector<ll>Ks(a,0);
    while(k>0){
      if(k%2==1)
        Ks[j]++;
      k/=2;
      j--;
    }
    for(int i=0; i<a; i++){
      if(Ks[i]==1 && Xs[i]==0)
        break;
      if(Ks[i]==0 && Xs[i]==1)
        Xs[i]=0;
    }
    for(int i=0; i<a; i++){
      X*=2;
      if(Xs[i]==1)
        X++;
    }  
  }
  ll ans=0;
  for(int i=0; i<N; i++)
    ans+=X^Y[i];
  cout<<ans<<endl;
}