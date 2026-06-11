#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W,D;
  cin>>H>>W>>D;
  vector<vector<int>>p(H*W+1,vector<int>(2));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      int a;
      cin>>a;
      p.at(a).at(0)=i,p.at(a).at(1)=j;
    }
  }
  vector<int>z(H*W+1);
  for(int i=0;i<D;i++){
    for(int j=1+i;j<=H*W-D;j+=D){
      z.at(j+D)=z.at(j)+abs(p.at(j+D).at(0)-p.at(j).at(0))+abs(p.at(j+D).at(1)-p.at(j).at(1));
    }
  }
  int Q;
  cin>>Q;
  for(int i=0;i<Q;i++){
    int l,r;
    cin>>l>>r;
    cout<<z.at(r)-z.at(l)<<endl;
  }
}