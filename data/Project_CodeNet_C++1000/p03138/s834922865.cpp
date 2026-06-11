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
#define debug(output) cout<<#output<<"= "<<output<<endl
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
lint solve(int n,lint k,vector<lint> a){
    lint sm=0;
    vector<int> memo(64,0);
    rep(i,n){
        sm+=a[i];
        rep(j,64){
            memo[j]+=a[i]%2;a[i]/=2;
        }
    }
    lint dp=0;lint use=0;
    vector<int> kbit;
    lint buf=k;
    while(buf>0){
        kbit.push_back(buf%2);buf/=2;
    }
    reverse(ALL(kbit));
    int keta=kbit.size();
    if(n-memo[keta-1]>memo[keta-1]){
        use=(n-2*memo[keta-1])*(1ll<<(keta-1));
    }
    rep1(i,keta-1){
        if(n-memo[keta-i-1]>memo[keta-i-1]){
            if(kbit[i]){
                dp=max(use,dp+(n-2*memo[keta-i-1])*(1ll<<(keta-i-1)));
                use+=(n-2*memo[keta-i-1])*(1ll<<(keta-i-1));
            }
            else{
                dp+=(n-2*memo[keta-i-1])*(1ll<<(keta-i-1));
            }
        }
        else if(kbit[i]){
            dp=max(dp,use);
        }
    }
    /*
    debug(use);
    debug(keta);
    debug(memo[0]);
    */
    return sm+max(dp,use);
}
signed main(){
  lint n,k;cin>>n>>k;
  vector<lint> a(n);
  rep(i,n)cin>>a[i];
  cout<<solve(n,k,a)<<"\n";
  return 0;
}