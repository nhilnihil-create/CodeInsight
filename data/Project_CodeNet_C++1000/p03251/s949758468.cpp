#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
  int n,m,x,y;cin>>n>>m>>x>>y;
  int z;
  rep(i,n){
    cin>>z;
    x=max(x,z);
  }
  rep(i,m){
    cin>>z;
    y=min(y,z);
  }
  y-x>0?cout<<"No War":cout<<"War";
}