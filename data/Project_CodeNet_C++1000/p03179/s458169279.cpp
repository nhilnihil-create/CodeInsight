#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long                           //del this if TLE or MLE
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fow(i,a,b,c) for(int i=a;i<=b;i+=c)
#define bck(i,a,b,c) for(int i=a;i>=b;i-=c)
#define F first
#define S second
#define loop int tests;cin>>tests;while(tests--)

const int mod=1e9+7;
const int N=3005;

int dp[N][N];

signed main() 
{
    fastio;
    int n;
    cin>>n;
    string s;
    cin>>s;
    dp[1][1]=1;
    fow(len,2,n,1) 
	{
        fow(i,1,n,1)
			dp[len-1][i]=(dp[len-1][i]+dp[len-1][i-1])%mod;
        fow(a,1,len,1)
		{
			int l,r;
			if(s[len-2]=='<')
				l=1,r=a-1;
			else
				l=a,r=len-1;
            if(l<=r)
				dp[len][a]=(dp[len][a]+(dp[len-1][r]-dp[len-1][l-1]+mod)%mod)%mod;
        }
    }
    int ans=0;
    fow(i,1,n,1)
		ans=(ans+dp[n][i])%mod;
    cout<<ans<<"\n";
}

