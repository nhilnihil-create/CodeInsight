#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
分岐の処理をどうするか
x軸y軸それぞれにプラマイ自由にできるか
最初のTまでだけ固定
わけられた数字のパーツあわせてxyにできるかどうか

2 3 5 7
8をつくる
せいぜい8000まで
mapとか8000*8000

ああ、いけたけど、DPでいいのか
*/
int main(){
  string S; cin>>S;
  ll X,Y; cin>>X>>Y;
  ll ssz=S.size(), i=0, tmp=0;
  vector<ll> A(0,0), B(0,0);
  vector<vector<bool>> DP1(8010,vector<bool>(8010,false)),DP2(8010,vector<bool>(8010,false));
  DP1[0][0]=true;
  DP2[0][0]=true;
  bool row=false;
  while(S[i]=='F' && i<ssz){
    X--;
    i++;
  }
  i++;
  while(i<ssz){
    if(S[i]=='T'){
      if(tmp>0) (row)?A.emplace_back(tmp):B.emplace_back(tmp);   
      row=(row)?false:true;
      tmp=0;
    }
    else tmp++;
    i++;
  }
  if(tmp>0) (row)?A.emplace_back(tmp):B.emplace_back(tmp);    
  ll asz=A.size(), bsz=B.size();
//cout<<"a:"<<asz<<" b:"<<bsz<<endl;  
  for(i=0; i<asz; i++){
    for(ll j=0; j<=8000; j++){
      if(DP1[i][j]){
        ll n=j+A[i], m=abs(j-A[i]);
        DP1[i+1][n]=true;
        DP1[i+1][m]=true;
      }
    }
  }
  for(i=0; i<bsz; i++){
    for(ll j=0; j<=8000; j++){
      if(DP2[i][j]){
        ll n=j+B[i], m=abs(j-B[i]);
        DP2[i+1][n]=true;
        DP2[i+1][m]=true;
      }
    }
  }
  X=abs(X),Y=abs(Y);
  if(DP1[asz][X] && DP2[bsz][Y]) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
//cout<<endl;
//for(auto v:A)cout<<v<<" ";
//cout<<endl;
//for(auto v:B)cout<<v<<" ";

}