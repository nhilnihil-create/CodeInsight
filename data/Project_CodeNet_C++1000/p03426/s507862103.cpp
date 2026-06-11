#include <bits/stdc++.h>
#include<math.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int H,W,D;
  cin>>H>>W>>D; 
  vector<vector<int>>a(H,vector<int>(W));
  rep(i,H){
    rep(j,W){
      cin>>a.at(i).at(j);
      a.at(i).at(j)--;
    }
  }
  int Q;
  cin>>Q;
  vector<int> l(Q),r(Q);
  rep(i,Q){
    cin>>l.at(i)>>r.at(i);
    l.at(i)--;
    r.at(i)--;
  }
  
  vector<vector<int>> dist(H*W, vector<int>(2));
  rep(i,H){  
    rep(j,W){
    dist.at(a.at(i).at(j)).at(0)=i;
    dist.at(a.at(i).at(j)).at(1)=j;
    }
  }

  vector<vector<int>>data(D,vector<int>(H*W/D+1));
  rep(i,D){
    for(int j=1;j<=(H*W-1)/D;j++){
      if(j*D+i>=H*W){
        data.at(i).at(j)=0;
      }
      else{
      data.at(i).at(j)=data.at(i).at(j-1)+abs(dist.at(i+j*D).at(0)-dist.at(i+(j-1)*D).at(0));
      data.at(i).at(j)+=abs(dist.at(i+j*D).at(1)-dist.at(i+(j-1)*D).at(1));
      }
    }
  }
  rep(i,Q){
    cout << data.at(l.at(i)%D).at(r.at(i)/D)-data.at(l.at(i)%D).at(l.at(i)/D)<< endl;
  }
}