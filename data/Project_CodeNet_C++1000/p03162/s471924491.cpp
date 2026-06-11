#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);

    rep(i,n)cin >> a[i]>> b[i] >> c[i];
    
    Graf dp(n+1,vector<int>(3));
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for(int i=1;i<=n;++i){
        dp[i][0]=max(dp[i-1][1]+a[i-1],dp[i-1][2]+a[i-1]);
        dp[i][1]=max(dp[i-1][0]+b[i-1],dp[i-1][2]+b[i-1]);
        dp[i][2]=max(dp[i-1][0]+c[i-1],dp[i-1][1]+c[i-1]);
    }
    int ans=max(dp[n][0],dp[n][1]);
    ans=max(ans,dp[n][2]);
    cout << ans << endl;
}