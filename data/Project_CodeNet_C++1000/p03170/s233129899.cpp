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
  int n,k;cin>>n>>k;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  sort(a.begin(),a.end());
  vector<bool> dp(k+1,false);
  for(int j=a[0];j<=k;++j){
      bool flag=false;
      rep(i,n){
          if(j<a[i])break;
          if(!dp[j-a[i]])flag=true;
      }
      dp[j]=flag;
  }
	if(dp[k]){
        cout<<"First"<<endl;
    }
    else{
        cout<<"Second"<<endl;
    }
  return 0;
}
