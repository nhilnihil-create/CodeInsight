#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
signed main(){
  double n,m,d;cin>>n>>m>>d;
  double mean=2*(n-d)/n/n*(m-1);
  if(d==0)mean/=2;
  printf("%.12lf\n",mean);
  return 0;
}
