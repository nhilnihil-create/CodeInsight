#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int x[2],y[2];
  cin>>x[0]>>y[0]>>x[1]>>y[1];
  int v[2]={y[0]-y[1],x[1]-x[0]};
  int dy=-1;int dx=1;
  int rx[2],ry[2];
  rx[0]=x[1]+v[0];
  ry[0]=y[1]+v[1];
  v[0]=x[0]-x[1];v[1]=y[0]-y[1];
  rx[1]=rx[0]+v[0];
  ry[1]=ry[0]+v[1];
  cout<<rx[0]<<" "<<ry[0]<<" "<<rx[1]<<" "<<ry[1]<<"\n";
  return 0;
}