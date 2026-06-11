#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
int lis(vector<int> const& a,int n){
    int res=0;
    int inf=1000000007;
    vector<int> dp(n+1,0);
    rep(i,n){
        dp[a[i]]=dp[a[i]-1]+1;
    }
    rep1(i,n){
        if(res<dp[i])res=dp[i];
    }
    return res;
}
signed main(){
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    int leng=lis(a,n);
    int res=n-leng;
    cout<<res<<endl;
    return 0;
}