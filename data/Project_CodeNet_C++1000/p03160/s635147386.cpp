#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define frr(j,i,n) for(int i=j;i<=n;++i)
using namespace std;
int n;
int a[100005];
int dp[100005];
int go(int index)
{
    if(index>=n)
        return 0;
    if(dp[index]!=-1)
        return dp[index];
    int x=abs(a[index]-a[index+1])+go(index+1);
    int y=1e6;
    if(index<n-1)
    y=abs(a[index]-a[index+2])+go(index+2);

    return dp[index]=min(x,y);
}
void solve()
{
	// int n;
    cin>>n;
    // int a[n+1];
    frr(1,i,n)  cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<go(1)<<"\n";

}
int main() 
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	// cin>>t;
	while(t--)
	solve();
	return 0;
}

