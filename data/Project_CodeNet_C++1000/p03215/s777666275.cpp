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
int n,k;
signed main(){
  cin>>n>>k;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  vector<int> sum(n+1,0);
  rep1(i,n){
      sum[i]=sum[i-1]+a[i-1];
  }
  vector<int> sub;
  rep(i,n){
      rep1(j,n){
          if(i>=j)continue;
          sub.push_back(sum[j]-sum[i]);
      }
  }
  int res=0;
  for(int i=60;i>=0;--i){
      int cnt=0;
      vector<int> buf;
      rep(j,sub.size()){
          if(sub[j]&(1ull<<i)){
              ++cnt;
              buf.push_back(sub[j]);
          }
      }
      if(cnt>=k){
          sub=buf;
          res|=(1ull<<i);
      }
  }
  cout<<res<<"\n";
  return 0;
}