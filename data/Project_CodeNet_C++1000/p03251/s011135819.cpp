#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  
  int xma=x;
  int a;
  rep(i,n){
    cin>>a;
    xma=max(xma,a);
  }
  int ymi=y;
  rep(i,n){
    cin>>a;
    ymi=min(ymi,a);
  }
  if(xma<ymi) cout<<"No War"<<endl;
  else cout<<"War"<<endl;

  return 0;
}