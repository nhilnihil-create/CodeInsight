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
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  vector<P> sum(n);
  int A=0;
  int T=0;
  rep(i,n){
      cin>>a[i]>>b[i];
      sum[i].first=a[i]+b[i];
      sum[i].second=i;
  }
  sort(sum.begin(),sum.end());
  for(int i=n-1;i>=0;--i){
      if((n-1-i)%2==0){
          T+=a[sum[i].second];
      }
      else{
          A+=b[sum[i].second];
      }
  }
  cout<<T-A<<endl;
  return 0;
}