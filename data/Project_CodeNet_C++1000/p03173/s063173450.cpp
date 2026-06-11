#include<bits/stdc++.h>
#define ll long long int
#define db long double
#define ull unsigned long long int
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
#define INF 1000000000
#define MOD 1000000007
#define MAXN 1000005
 
using namespace std;

ll dp[405][405];
ll a[405];

ll recur(ll i,ll j)
{
	if(j<i) return 0;
	if(i==j) return 0;
	// if(j==i+1) return a[i]+a[j];
	if(dp[i][j]!=-1) return dp[i][j];

	ll res=5000000000000;
	ll sum=0;
	rep(k,i,j) sum+=a[k];
	for(ll k=i;k<j;k++)
	{
		res=min(res,recur(i,k)+recur(k+1,j)+sum);
	}
	return dp[i][j]=res;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests=1;
    // cin>>tests;
    while(tests--)
    {
    	ll i,j,n;
    	cin>>n;
    	rep(i,1,n) cin>>a[i];
    	memset(dp,-1,sizeof(dp));

    	cout<<recur(1,n);

    }
    	return 0;
    
}