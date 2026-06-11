#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=3e3+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n;
char sig[mxN];
int dp[mxN][mxN];
int mod(int a){int ret=a%M;if(ret<0)ret+=M;return ret;};
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)cin>>sig[i];
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            /*for(int k=1;k<=i-1;k++){
                if(sig[i-1]=='<'){
                    if(j>k)dp[i][j]+=dp[i-1][k];
                }
                else{
                    if(j<=k)dp[i][j]+=dp[i-1][k];
                }
            }*/
            if(sig[i-1]=='<'){
                dp[i][j]=mod(dp[i-1][j-1]+dp[i][j]);
            }
            else{
                dp[i][j]=mod(dp[i][j]+dp[i-1][i-1]-dp[i-1][j-1]);
            }
            dp[i][j]=mod(dp[i][j]+dp[i][j-1]);
        }
    }
    cout<<mod(dp[n][n]);
}