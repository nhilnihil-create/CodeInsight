#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<functional>
#include<vector>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int N,M;
  cin>>N>>M;
  char table[N][M];
  rep(i,N){
    rep(j,M){
      cin>>table[i][j];
    }
  }
  rep(i,N){
    rep(j,M){
      if(table[i][j]=='#') continue;
      int cnt=0;
      if(i-1>=0&&j-1>=0){
        if(table[i-1][j-1]=='#') cnt++;
      }
      if(i-1>=0&&j>=0){
        if(table[i-1][j]=='#') cnt++;
      }
      if(i-1>=0&&j+1<M){
         if(table[i-1][j+1]=='#') cnt++;
      }
      if(i>=0&&j-1>=0){
        if(table[i][j-1]=='#') cnt++;
      }
      if(i>=0&&j+1<M){
        if(table[i][j+1]=='#') cnt++;
      }
      if(i+1<N&&j-1>=0){
        if(table[i+1][j-1]=='#') cnt++;
      }
      if(i+1<N&&j>=0){
        if(table[i+1][j]=='#') cnt++;
      }
      if(i+1<N&&j+1<M){
        if(table[i+1][j+1]=='#') cnt++;
      }
      table[i][j]=cnt+'0';
    }
  }
  rep(i,N){
    rep(j,M){
      cout<<table[i][j];
    }
    cout<<endl;
  }
}