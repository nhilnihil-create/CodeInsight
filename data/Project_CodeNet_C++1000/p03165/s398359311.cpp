#include<bits/stdc++.h>
#define ll long long int
#define db long double 
#define ull unsigned long long int
// #define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
// #define INF 10000000000000
#define MOD 1000000007
#define MAXN 200005
 
using namespace std;


vector<ll> g[200005];
ll subtree[200005],a[200005],ans[200005];
bool blocked[200005];

void dfs1(ll root,ll par)
{
	int cnt=0;
	for(auto x:g[root])
	{
		if(x!=par && !blocked[x])
			{
				cnt++;
				dfs1(x,root);
				subtree[root]+=subtree[x];
			}
	}
	if(cnt==0) subtree[root]=1;
	else
	subtree[root]++;
}

ll best;
void dfs2(ll &root,ll cur,ll par,ll &res)
{
	for(auto x:g[cur])
	{
		if(x!=par && !blocked[x])
		{
			dfs2(root,x,cur,res);
			ll mx=max(subtree[x],subtree[root]-subtree[cur]);
			if(mx<best)
			{
				best=mx;
				res=cur;
			}
		}
	}
}

ll find_centroid(ll root)
{
	subtree[0]=-1;
	subtree[root]=0;
	dfs1(root,0);
	ll res=root;
	best=INT_MAX;
	dfs2(root,root,0,res);
	return res;
}

ll dfs3(ll cur,ll par,ll val,vector<ll>&vv)
{

	vv.pb(val);

	for(auto x:g[cur])
	{
		if(x!=par && !blocked[x])
			dfs3(x,cur,(val^a[x]),vv);
	}
}

ll dp[3001][3001];

int main()
{
    int tests=1;
    // cin>>tests;
    while(tests--)
    {
    	ll i,j,n,m;
    	string s,t;
    	cin>>s>>t;
    	n=s.length();
    	m=t.length();
    	rep(i,1,n)
    	{
    		rep(j,1,m)
    		{
    			if(s[i-1]==t[j-1])
    			{
    				dp[i][j]=1+dp[i-1][j-1];
    			}
    			else
    			{
    				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    			}
    		}
    	}
    	string ans;
    	i=n,j=m;
    	while(i>0 && j>0)
    	{
    		if(s[i-1]==t[j-1])
    		{
    			ans.pb(s[i-1]);
    			i--;
    			j--;
    		}
    		else
    		{
    			if(dp[i-1][j]>=dp[i][j-1])
    				i--;
    			else
    				j--;
    		}
    	}
    	reverse(all(ans));
    	cout<<ans;

    }

    return 0;
}
    