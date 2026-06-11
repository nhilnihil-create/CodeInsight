#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n,z,w;cin>>n>>z>>w;
  vector<int> a(n+1,0);
  rep(i,n)cin>>a[i];
  int Max=z;int Min=z;int sub=z;
  rep(i,n){
    Max=a[i];
    Min=a[i];
  }
  rep(i,n-1){
    sub=a[i];
  }
  int res=abs(Max-w);
  res=max(res,abs(Min-w));
  res=max(res,min(abs(sub-a[n-1]),abs(sub-inf*1000)));
  if(n==1){
    res=abs(a[0]-w);
  }
  cout<<res<<endl;
  return 0;
}
