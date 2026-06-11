#include <bits/stdc++.h>  
using namespace std;
const int nax=3005;
const long long MOD=(long long)(1e9+7);
int dp[nax][nax];

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    dp[1][1]=1;
    for(int i=2;i<=n;i++)
    { 
    vector<int> prefix_sums(n,0);
    
        for(int now =1;now<i;now++)
        prefix_sums[now]=(prefix_sums[now-1]+dp[i-1][now])%MOD;
        for (int now=1;now<=i;now++)
        {
           
           
            int L,R;
                if(s[i-2]=='>')
                {
                 L=now;R=i-1;
                }
                else
                {
                    L=1;R=now-1;
                }
                if(L<=R)
                dp[i][now]=(dp[i][now]+prefix_sums[R]-prefix_sums[L-1]+MOD)%MOD; 
        }
    }
    
    int ans=0;
 for(int i=0;i<=n;i++)
    ans=(ans+dp[n][i])%MOD;
    cout<<ans;
    return 0;
}




