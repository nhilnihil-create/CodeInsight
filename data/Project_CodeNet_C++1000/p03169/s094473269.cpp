#include<bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lengthof(x) (sizeof(x) / sizeof(*(x)))
#define int long long
#define eps (1e-7)
#define inf (1e9)
#define md (1000000007)
#define MAX 301
double dp[MAX][MAX][MAX];
double rec(int i,int j,int k,int n){
    if(dp[i][j][k]>=0)
        return dp[i][j][k];
    if(i==0&&j==0&&k==0)
        return 0.0;
    double res=(double)n;
    if(i>0)
        res+=rec(i-1,j,k,n)*i;
    if(j>0)
        res+=rec(i+1,j-1,k,n)*j;
    if (k>0)
        res+=rec(i,j+1,k-1,n)*k;
    res*=1.0/(i+j+k);
    return dp[i][j][k]=res;
}
signed main() {
    fast_io
    int t,n,c[4]={0,0,0,0};
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>t;c[t]++;
    }
    memset(dp,-1,sizeof(dp));
    cout<<fixed<<setprecision(10)<<rec(c[1],c[2],c[3],n)<<endl;
    return 0;
}
