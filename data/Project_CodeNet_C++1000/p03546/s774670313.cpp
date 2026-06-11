#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1001001001;



int main() {

  int h,w;
  cin>>h>>w;
  int v[10][10];
//  int V[10][10];
  rep(i,10)rep(j,10)v[i][j]=INF;
  rep(i,10)rep(j,10)cin>>v[i][j];
  rep(i,10)rep(j,10)rep(k,10){
    v[j][k]=min(v[j][k],v[j][i]+v[i][k]);
  //cout<<v[i][j]<<'i'<<i<<'j'<<j<<'k'<<k<<endl;
  }
  int ans=0;
  rep(i,h)rep(j,w){
    int a1;cin>>a1;
    if (a1==-1)continue;
    ans+=v[a1][1];
  //  cout<<i<<' '<<j<<' '<<ans<<endl;
  }

cout<<ans;
}
