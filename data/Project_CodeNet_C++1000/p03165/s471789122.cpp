#include<bits/stdc++.h>
using namespace std;
//#define int 					ll
#define ios	    				ios_base::sync_with_stdio(false); cin.tie(0)
#define hell 					1000000007
#define inf 					9e18

// Data Structures //
#define ull 					unsigned long long
#define ll 						long long
#define p_q 					priority_queue
#define pii         			pair<ll,ll>
#define vi          			vector<ll>
#define vii         			vector<pii>
#define mi          			map<ll,ll>
#define mii         			map<pii,ll>
// Functions //
#define pb 						push_back
#define ppb						pop_back
#define all(a)      			(a).begin(),(a).end()
#define gcd(a,b)    			__gcd((a),(b))
#define lcm(a,b)    			((a)*(b)) / gcd((a),(b))
#define mp 						make_pair
#define bs						binary_search
#define lb 						lower_bound
#define ub						upper_bound
#define F						first
#define S						second
#define take(a,n)				for(ll i=0;i<n;i++) cin>>a[i];
#define dbg(x) 					cout << #x << " = " << x << '\n'
#define endl					"\n"
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define N  1000005

void solve()
{
	string s,t,u;
	ll n,m,k=0,cnt=0,mx=-hell,mn=hell;
	cin>>s>>t;
	m = s.size();
	n = t.size();
	ll dp[m+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i-1]==t[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
		}
	}
	ll i=m,j=n;
	for(int k=0;k<=m+n;k++)
	{
		if(i==0||j==0) break;
		if(s[i-1]==t[j-1])
		{
			u.pb(s[i-1]);
			i--; j--;
		}
		else if(dp[i][j-1]>=dp[i-1][j])
		{
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		{
			i--;
		}
	}
	reverse(u.begin(),u.end());
	cout<<u<<endl;
}


signed main()
{
	ios;
	ll n,tests=1,prev=0,i=0;

	while(tests--)
	{
		solve();
	}
	time
	return 0;
}
