#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,n,sr,sc;
  cin>>h>>w>>n>>sr>>sc;
  vector<int> sx(n);
  vector<int> sy(n);
  for(int i=0;i<n;i++){
    char c;
    cin>>c;
    sx.at(i)=(c=='L'?-1:(c=='R'?1:0));
    sy.at(i)=(c=='U'?-1:(c=='D'?1:0));
  }
  vector<int> tx(n);
  vector<int> ty(n);
  for(int i=0;i<n;i++){
    char c;
    cin>>c;
    tx.at(i)=(c=='L'?-1:(c=='R'?1:0));
    ty.at(i)=(c=='U'?-1:(c=='D'?1:0));
  }
  int l=0;
  int r=w+1;
  int u=0;
  int d=h+1;
  for(int i=n-1;i>=0;i--){
    if(tx.at(i)==-1)
      r=min(r+1,w+1);
    if(tx.at(i)==1)
      l=max(l-1,0);
    if(ty.at(i)==-1)
      d=min(d+1,h+1);
    if(ty.at(i)==1)
      u=max(u-1,0);
    if(sx.at(i)==-1)
      l++;
    if(sx.at(i)==1)
      r--;
    if(sy.at(i)==-1)
      u++;
    if(sy.at(i)==1)
      d--;
    if(l+1>=r||u+1>=d)
      break;
  }
  cout<<(u<sr&&d>sr&&l<sc&&r>sc?"YES":"NO")<<endl;
}