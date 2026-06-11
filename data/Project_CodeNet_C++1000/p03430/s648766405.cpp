#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
using namespace std;
const int N = 3e2+10;
int dp[N][N][N];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;cin>>s;
    int k;cin>>k;
    int n=s.length();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<=n;j++)
            for(int ch=0;ch<=k;ch++){
                int curr=j-i;
                //cout<<curr;
                if(curr!=j){
                    if(s[curr-1]!=s[j-1]){
                        dp[j][curr][ch]=max(dp[j-1][curr][ch],dp[j][curr+1][ch]);
                        if(ch>0)
                            dp[j][curr][ch]=max(2+dp[j-1][curr+1][ch-1],dp[j][curr][ch]);
                        continue;
                    }
                    else
                        dp[j][curr][ch]=2+dp[j-1][curr+1][ch];
                }
                else
                    dp[j][curr][ch]=1;
            }
    cout<<dp[n][1][k];
}

