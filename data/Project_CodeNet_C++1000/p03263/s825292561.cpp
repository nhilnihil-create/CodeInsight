#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;


int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<int>> a(h,vector<int>(w));
  rep(i,h)rep(j,w) cin>>a[i][j];
  
  vector<vector<int>> d(h,vector<int>(w));
  int res=0;
  rep(i,h-1){
    rep(j,w){
      if(a[i][j]%2==0) continue;
      d[i][j]=1;
      res++;
      a[i][j]--;
      a[i+1][j]++;
    }
  }
  rep(j,w-1){
    if(a[h-1][j]%2==0) continue;
    d[h-1][j]=1;
    res++;
    a[h-1][j]--; 
    a[h-1][j+1]++;
  }
  
  cout<<res<<endl;
  rep(i,h-1)rep(j,w){
    if(d[i][j]==1){
      cout<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+1<<endl;
    }
  }
  rep(j,w){
    if(d[h-1][j]==1){
      cout<<h<<" "<<j+1<<" "<<h<<" "<<j+2<<endl;
    }
  }
}
  