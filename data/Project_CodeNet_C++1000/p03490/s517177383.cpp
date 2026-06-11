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
*/
int main(){
  string S; cin>>S;
  ll X,Y; cin>>X>>Y;
  ll ssz=S.size(), i=0, tmp=0;
  vector<ll> A(0,0), B(0,0);
  map<ll,bool> M1,M2,M3,M4;
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
  M2[0]=true;
  ll asz=A.size(), bsz=B.size();
//cout<<"a:"<<asz<<" b:"<<bsz;  
  for(i=0; i<asz; i++){
    M1=M2;
    M2.clear();
    for(auto v:M1){
      ll v1=v.first;
      M2[v1+A[i]]=true;
      M2[v1-A[i]]=true;
    }
  }
  M4[0]=true;
  for(i=0; i<bsz; i++){
    M3=M4;
    M4.clear();
    for(auto v:M3){
      ll v1=v.first;
      M4[v1+B[i]]=true;
      M4[v1-B[i]]=true;
    }
  }
  if(M2[X] && M4[Y]) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

//cout<<endl;
//for(auto v:A)cout<<v<<" ";
//cout<<endl;
//for(auto v:B)cout<<v<<" ";

}