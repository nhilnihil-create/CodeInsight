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
ll dp[100000+5];
ll n;
ll A[100000+5];
ll dpcall(ll pos)
{
	if(pos>=n-1)
		return 0;
	if(dp[pos]!=-1)
		return dp[pos];
	ll r1=INT_MAX,r2=INT_MAX;
	if((pos+1)<n)
		r1=abs(A[pos+1]-A[pos])+dpcall(pos+1);
	if((pos+2)<n)
		r2=abs(A[pos+2]-A[pos])+dpcall(pos+2);
	return dp[pos]=min(r1,r2);
}
void solve()
{
    //Code here
 	memset(dp,-1,sizeof(dp));
 	ci>>n;
 	for(int i=0 ; i<n ; i++)
 	{
 		ci>>A[i];
 	}
 	co<<dpcall(0);
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