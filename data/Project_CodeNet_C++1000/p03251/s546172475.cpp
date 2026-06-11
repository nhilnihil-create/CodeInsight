#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  int xg=x;
  for(int i=0;i<n;i++){
    int xi;
    cin>>xi;
    xg=max(xg,xi);
  }
  int yl=y;
  for(int i=0;i<m;i++){
    int yi;
    cin>>yi;
    yl=min(yl,yi);
  }
  cout<<(xg<yl?"No War":"War")<<endl;
}