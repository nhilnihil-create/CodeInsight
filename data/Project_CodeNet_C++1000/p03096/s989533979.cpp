#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1000000007;

int n,cnt;
int c[200005];
int pre[200005];
int dp[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    dp[0]=1;
    cnt=1;
    for(int i=1;i<=n;i++){
        cin>>c[cnt];
        if(c[cnt]!=c[cnt-1])cnt++;
    }
    n=cnt-1;
    for(int i=1;i<=n;i++){
        dp[i]=(dp[i-1]+pre[c[i]])%mod;
        pre[c[i]]=(pre[c[i]]+dp[i-1])%mod;
        //cerr<<dp[i]<<' ';
    }
    //cerr<<endl;
    cout<<dp[n]<<endl;

    return 0;
}