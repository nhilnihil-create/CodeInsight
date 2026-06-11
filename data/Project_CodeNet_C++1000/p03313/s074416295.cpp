//	ZapZu's code hohoho
//	#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define dfs_black 1
#define dfs_white -1
#define pr pair
#define vt vector
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef double db;
typedef long long li;
typedef long double ld;

typedef pr<int, int> ii;
typedef pr<ld,ld> dd;

typedef vt<int> vi;
typedef vt<li> vli;
typedef vt<ld> vld;
typedef vt<ii> vii;

typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, char> mic;

typedef set<int> s_i;
typedef set<char> s_c;

const int MOD = 1e9+7;
const li INF = 1e18;
const ld PI = 4*atan((ld)1);
int a[1000000];
int dp[1000000];
signed main()
{
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
fastio;
	int n;
	cin>>n;
	for(int i=0; i<(1<<n); i++)
	{
		cin>>a[i];
	}
	for (int mask = 1; mask < (1<<n); mask++)
	{		
		int t1=0, t2=0;
	    for(int i = mask; ; i = (i-1) & mask)
		{
//			cout<<a[i]<<" ";
			if(t1<a[i]) 
			{
				t2=t1;
				t1=a[i];
			}
			else if(t2<a[i]) t2=a[i];
			if(!i) break;
		}
//		cout<<endl;
//		cout<<t1<<" "<<t2<<endl; 
		dp[mask]=max(dp[mask-1], t1+t2);
		cout<<dp[mask]<<endl;
    }
}


