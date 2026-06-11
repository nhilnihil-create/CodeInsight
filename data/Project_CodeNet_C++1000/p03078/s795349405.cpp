#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
//全部priority_queueにつっこんだんじゃ、1000^3のsortでTLE。
//入れる数制限しないと
/*
struct cake{
  ll i;
  ll j;
  ll k;
};
*/
//pqに、はじめABCの1番目を入れる
//つぎに211,121,112を入れてメモしておく
//とりだしたのが211だったら、311,221,212をいれる
//このとき入ってないかの判定がむずいな
//4次元配列作る？1000*1000*1000*2とか無理くさいか
//3次元配列のmapって可能なんだっけ
//いけた。boolの初期値=0=false
//pqにいれたらtrueにしとく。
//trueだったらスルー、なかんじでいけそう
//structでpqのなかにいれようとしたらなんかエラー

int main(){
  ll X,Y,Z,K,i,j,k;
  cin>>X>>Y>>Z>>K;
  vector<ll> A(X,0),B(Y,0),C(Z,0),tmp(3,0);
  priority_queue<pair<ll,vector<ll>>> pq;
  map<vector<ll>,bool> mp;
  FOR(i,X){
    ll a; cin>>a; A[i]=a;
  }
  FOR(i,Y){
    ll b; cin>>b; B[i]=b;
  }
  FOR(i,Z){
    ll c; cin>>c; C[i]=c;
  }
  sort(A.begin(), A.end(), greater<ll>());
  sort(B.begin(), B.end(), greater<ll>());
  sort(C.begin(), C.end(), greater<ll>());
  pq.push(make_pair(A[0]+B[0]+C[0],tmp));
  mp[tmp]=true;
  FOR(i,K){
    cout<<pq.top().first<<endl;
    vector<ll> d=pq.top().second;
    pq.pop();
    FOR(j,3){
      d[j]++;
      if(!mp[d] &&d[0]<X &&d[1]<Y &&d[2]<Z){
        pq.push(make_pair(A[d[0]]+B[d[1]]+C[d[2]],d));
        mp[d]=true;
      }
      d[j]--;
    }
  }
}