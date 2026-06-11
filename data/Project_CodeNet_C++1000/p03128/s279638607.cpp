#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int req[10]={0,2,5,5,4,5,6,3,7,6};
    int n,m;cin>>n>>m;
    int a[m];
    for (int i=0;i<m;i++)
        cin>>a[i];
    sort(a,a+m,greater<int>());
    int dp[n+1];
    fill(dp,dp+n+1,-1);
    dp[0]=0;
    for (int i=0;i<m;i++)
        for (int j=req[a[i]];j<=n;j++)
            if (dp[j-req[a[i]]]!=-1)
                dp[j]=max(dp[j],dp[j-req[a[i]]]+1);
    string ans;
    for (int i=n,j=0;j<m;j++)
        if (i-req[a[j]]>=0&&dp[i]-1==dp[i-req[a[j]]]) {
            ans+=to_string(a[j]);
            i-=req[a[j]];
            j=-1;
        }
    cout<<ans<<endl;
    return 0;
}