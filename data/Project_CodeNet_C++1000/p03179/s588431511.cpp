#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define ll long long int

void add_self(ll& a,ll b){
   a+=b;
   if(a>=mod) a-=mod;
}

int main()
{
    int n;
    string s;
    cin>>n;cin>>s;
    //dp[i][j] represents the number of ways to arrange the number upto length i and last number is j
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    dp[1][1]=1;
     for(int len=2;len<=n;len++){
            //calculation of prefix sum upto length len
            vector<ll> prefix_sum(n+1);
            for(int i=1;i<=len;i++){
                add_self(prefix_sum[i],(prefix_sum[i-1]+dp[len-1][i])%mod);
            }

        for(int b=1;b<=len;b++){
            int L,R;
            if(s[len-2]=='<'){
                L=1;R=b-1;
            }
            else{
                L=b;R=len-1;
            }
            if(L<=R)
            add_self(dp[len][b],(prefix_sum[R]-prefix_sum[L-1]+mod)%mod);
        }

     }
     ll answer=0;
     for(int i=1;i<=n;i++){
        add_self(answer,dp[n][i]);
     }
     cout<<answer;
}
