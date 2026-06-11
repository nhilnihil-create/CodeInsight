#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define line cout<<"\n"
#define ci std ::cin
#define co std ::cout
#define sf scanf
#define sff(n,m) scanf("%d%d",&n,&m)
#define pf printf
#define p_line printf("\n")
#define cas(n) printf("Case %d: ",n++)
#define task return
#define loop(x,n)  for(int x = 0 ; x < n ; x++)
#define constloop(x,a,n) for(int x = a ; x < n ; x++)
#define revloop(x,a,n)  for(int x = a ; x >= n ; x--)
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi acos(-1)
#define mx 10000000
/*ll P[mx+5],cnt=1;
bool nP[mx+5];
void sieve(void)
{
    P[0]=2;
    nP[0]=true;
    nP[1]=true;
    for(ll i=3 ; i<=mx ; i+=2)
    {
        if(nP[i]==true)
            continue;
        for(ll j=i+i ; j<=mx ; j+=i)
            nP[j]=true;
        P[cnt++]=i;
    }
}*/
int dp[100000+5];
int A[100000+5];
int n,k;
int dpcall(int pos)
{
	if(pos>=n-1)
		return 0;
	if(dp[pos]!=-1)
		return dp[pos];
	vector<int>v;
	for(int i=1 ; i<=k ; i++)
	{
		if(pos+i<n)
		{
			v.pb(abs(A[pos]-A[pos+i])+dpcall(pos+i));
		}
	}
	int ans=INT_MAX;
	for(int i=0 ; i<v.size() ; i++)
	{
		ans=min(ans,v[i]);
	}
	return dp[pos]=ans;
}
void solve()
{
    //Code here
 	ci>>n>>k;
 	for(int i=0 ; i<n ; i++)
 	{
 		ci>>A[i];
 	}
 	memset(dp,-1,sizeof(dp));
 	co<<dpcall(0);
 	line;
}
int main()
{
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
	solve();
	return 0;
}