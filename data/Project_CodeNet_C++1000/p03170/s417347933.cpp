#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define vi vector <int>
#define endl "\n"
#define f(n) for(int i=0;i<n;i++)
#define vvi vector <vector<int> >
#define vii vector <pair<int,int> >
#define rep(i,a,b) for (int i=a;i<b;i++)
#define repD(i,a,b) for (int i=a;i>=b;i--)
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define gcd __gcd
#define init(i,k) memset(i,k,sizeof i)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define setBits(x) __builtin_popcountll(x)
#define pii pair <int,int>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define N 100005
#define mod 1000000007
int dp[N];
void solve()
{
	int n,k;
	cin>>n>>k;
	vi v(n);
	f(n)
		cin>>v[i];
	sort(v.begin(),v.end());
	for(int i=1;i<=k;i++)
	{
		for(auto x:v)
		{
			if(x<=i)
			{
				if(dp[i-x]==0)
				{
					dp[i]=1;
				}
			}
		}
	}
	if(dp[k]==1)
	{
		cout<<"First"<<endl;
	}
	else
	{
		cout<<"Second"<<endl;
	}
	return;
}
signed main()
{
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
    	//cout<<"Case #"<<i<<": ";
    	solve();
    	//cout<<endl;
    }
    return 0;
}