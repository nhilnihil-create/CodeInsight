#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

#define Pb push_back
#define Mp make_pair

#define ff first
#define ss second

#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN

#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define db1(x) cout<<#x<<" : "<<x<<endl;
#define db2(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;
#define db3(x,y,z) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<endl;

#define ll ld

ll dp[301][301][301];

ll sol(int one,int two,int three,int &n)
{
	if(one < 0 || two < 0 || three < 0)
	{
		return 0;
	}
	if(three == 0 && two == 0 && one == 0)
	{
		return 0;
	}
	if(dp[one][two][three] > 0)
	{
		return dp[one][two][three];
	}
	int rem = one + two + three;
	ll ex_val = n + one * sol(one-1,two,three,n) +  two * sol(one+1,two-1,three,n) +  three* sol(one,two+1,three-1,n);
	return dp[one][two][three] = ex_val/rem;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> cnt(4,0);
	for(int i=0,x;i<n;i++)
	{
		cin >> x;
		cnt[x]++;
	}
	memset(dp,-1,sizeof(dp));
	cout << fixed << setprecision(12) << sol(cnt[1],cnt[2],cnt[3],n);
}

signed main()
{
   IOS;
   int t = 1;
   //cin >> t;
   while(t--)
   {
      solve();
   }
   return 0;
}


/*==============================================================================================================================================================*/
