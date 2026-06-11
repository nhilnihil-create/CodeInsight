#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
typedef long long ll;
#define loop() for(int i=0; i<(); i++)
const int MOD=1e9+7;
int modpow(int x, int n, int m)
{
    if(n==0) return 1;
    ll ans=1;
    while(n>0)
    {
        if(n%2==1) ans=(ans*x)%m;
        x=(x*x)%m;
        n/=2;
    }
    return ans;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<vector<ll>>dp(n,vector<ll>(n,0)),s(n,vector<ll>(n,0));
    for(int i=0; i<n; i++) s[i][i]=a[i];
    for(int i=0; i<n-1; i++)
    {
        dp[i][i+1]=a[i]+a[i+1];
        s[i][i+1]=a[i]+a[i+1];
    }
    
    for(int k=2; k<n; k++)
    {
        int i=0,j=k;
        while(j<n)
        {
            dp[i][j]=LLONG_MAX;
            s[i][j]=LLONG_MAX;
            for(int r=i; r<j; r++)
            {
                if(dp[i][r]+dp[r+1][j]+s[i][r]+s[r+1][j]<dp[i][j])
                {
                    dp[i][j]=dp[i][r]+dp[r+1][j]+s[i][r]+s[r+1][j];
                    s[i][j]=s[i][r]+s[r+1][j];
                }
            }
            i++;
            j++;
        }
    }
 cout<<dp[0][n-1]<<endl;
    
}   

int main(){
	fast
	int t=1;
	//cin>>t;
	while(t--) 
    {
        solve();
    }

}
