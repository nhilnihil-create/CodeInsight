#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W,h,w;
  cin>>H>>W>>h>>w;
  vector<vector<char>>A(H,vector<char>(W,'o'));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      for(int l=0;l<W;l++){
        A.at(i).at(l)='x';
      }
      for(int k=0;k<H;k++){
        A.at(k).at(j)='x';
      }
    }
  }
  int cnt=0;
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        if(A.at(i).at(j)=='o')cnt++;
    }
  }
  cout<<cnt<<endl;
  
}