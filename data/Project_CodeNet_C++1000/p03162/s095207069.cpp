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
int a[100005],b[100005],c[100005];
ll dp[100005][2][2][2];
ll go(int index,int A,int B,int C)
{
    if(index>n)
        return 0;
    if(dp[index][A][B][C]!=-1)
        return dp[index][A][B][C];
    ll x=0,y=0,z=0;
    if(A)
        x=a[index]+go(index+1,0,1,1);
    if(B)
        y=b[index]+go(index+1,1,0,1);
    if(C)
        z=c[index]+go(index+1,1,1,0);
    
    return dp[index][A][B][C]= max(x,max(y,z));
    
}

void solve()
{
    memset(dp,-1,sizeof(dp));
	cin>>n;
    frr(1,i,n)
    {
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
    }
    cout<<go(1,1,1,1);
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

