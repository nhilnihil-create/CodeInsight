#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<int>> G(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>G[i][j];
    }
  }
  vector<int> p;
  for(int i=1;i<H*W;i++){
    int a,b,c,d;
    a=(i-1)/W,b=(i-1)%W,c=i/W,d=i%W;
    if(a%2==1){
      b=W-1-b;
    }
    if(c%2==1){
      d=W-1-d;
    }
    if(G[a][b]%2){
      G[c][d]++;
      p.push_back(i);
    }
  }
  int N=p.size();
  cout<<N<<endl;
  for(int i=0;i<N;i++){
    int a,b,c,d;
    a=(p[i]-1)/W,b=(p[i]-1)%W,c=p[i]/W,d=p[i]%W;
    if(a%2==1){
      b=W-1-b;
    }
    if(c%2==1){
      d=W-1-d;
    }
    a++,b++,c++,d++;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
  }
}