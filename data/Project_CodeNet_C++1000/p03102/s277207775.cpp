#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) x.begin(), x.end()
using namespace std;
int main(){
  int n,m,c;
  cin>>n>>m>>c;
  vector<int> b(m);
  vector<vector<int>> a(n,vector<int>(n));
  rep(i,m) cin>>b[i];
  rep(i,n){
    rep(j,m){
      cin>>a[i][j];
    }
  }
  int ans=0;
  rep(i,n){
    int sum=0;
    rep(j,m){
      sum+=a[i][j]*b[j];
    }
    if(sum+c>0) ans++;
  }
  cout<<ans<<endl;
}