#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,Q;
  string S;
  cin>>N>>Q>>S;
  vector<pair<char,char>> A(Q);
  for(pair<char,char> &p:A)cin>>p.first>>p.second;
  int ok=-1,ng=N;
  while(ng-ok>1){
    int n=(ok+ng)/2,m=n;
    for(pair<char,char> p:A){
      if(S[m]==p.first){
        if(p.second=='R')m++;
        else m--;
      }
      if(m==-1){
        ok=n;
        goto home;
      }
      if(m==N){
        ng=n;
        goto home;
      }
    }
    ok=n;
    home:;
  }
  int mx=ok;
  ok=N,ng=-1;
  while(ok-ng>1){
    int n=(ok+ng)/2,m=n;
    for(pair<char,char> p:A){
      if(S[m]==p.first){
        if(p.second=='R')m++;
        else m--;
      }
      if(m==-1){
        ng=n;
        goto home2;
      }
      if(m==N){
        ok=n;
        goto home2;
      }
    }
    ok=n;
    home2:;
  }
  cout<<mx-ok+1<<endl;
}