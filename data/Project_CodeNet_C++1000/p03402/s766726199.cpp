#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b;
  cin>>a>>b;
  char c[100][100];
  rep(i,0,50){
    rep(j,0,100){
      c[i][j]='.';
    }
  }
  rep(i,50,100){
    rep(j,0,100){
      c[i][j]='#';
    }
  }
  int cur=1;
  for(int i=0;i<50;i+=2){
    for(int j=0;j<100;j+=2){
      if(cur==b) break;
      c[i][j]='#';
      cur++;
    }
    if(cur==b) break;
  }
  cur=1;
  for(int i=51;i<100;i+=2){
    for(int j=0;j<100;j+=2){
      if(cur==a) break;
      c[i][j]='.';
      cur++;
    }
    if(cur==a) break;
  }
  cout<<100<<' '<<100<<endl;
  rep(i,0,100){
    rep(j,0,100){
      cout<<c[i][j];
    }
    cout<<endl;
  }
}