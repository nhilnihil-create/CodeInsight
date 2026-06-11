#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
全探索でいけるのかな
2点間のとりかたnC2
そのくみあわせ、nC2*nCk
すくなくとも1000^4むりじゃね
効率化･･･
基本的には数が大きいもの同士？
4 2
2 5 2 5

2,4,5,7,9,10,12,14
2=   10
4=  100
5=  101
7=  110
9= 1001
10=1010
12=1100
14=1110

12+14=1100=12

2,5
2= 10
5=101
7=111
和の時点で法則、あるっちゃあるか
1000個とかになると、コントロールきつい

一番外側のBITを満たすものがあるか調べる
すくなくともnC2通り全部は可能
成立しないなら次の桁
最大何桁になる、13桁くらいならnC2*10でいけるか
対象をしぼる必要あるかな
あるか
どうやって抜こう
queueのコピーってできるかな
  queue<ll> A,B;
  A.emplace(1);
  B=A;
  cout<<B.front()<<endl;
でるんかい
true=1
13桁じゃないわ
10^13=2^? 43
*/
int main(){
  ll N,K,ans=0; cin>>N>>K;
  queue<ll> A,B,W;//Aは対象、Bはバックアップ用、Wは作業
  vector<ll> C(N+1,0);
  for(ll i=1; i<=N; i++) cin>>C[i];
  for(ll i=1; i<=N; i++) C[i]=C[i-1]+C[i];
  for(ll i=1; i<=N; i++) for(ll j=0; j<i; j++) A.emplace(C[i]-C[j]);
  //外側のBITから全探索
  B=A;
  for(ll i=50; i>=0; i--){
    A=B;
    queue<ll> emp;
    W.swap(emp);
    while(!A.empty()){
      ll n=A.front(); A.pop();
      if(1&n>>i) W.emplace(n);
    }
    if(W.size()<K) continue;
    //必要量があるとき
    B=W;
  }
  //最後BかCに必要なくみあわせがはいってる
  if(!B.empty()){
    ans=B.front();
    B.pop();
  }
  while(!B.empty() && --K>0){
    ans=ans&B.front();
    B.pop();
  }
  cout<<ans<<endl;
}