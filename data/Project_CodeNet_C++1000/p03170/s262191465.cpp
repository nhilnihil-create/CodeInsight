	#include <bits/stdc++.h>
	#include <set>
	#define ll long long 
	#include <string>
	#define pb push_back
	#define mp make_pair
	# define pi 3.14159265358979323846
	#define mod 1000000007
    #define rep(i,n) for(i=0;i<n;i++)
    #define rep1(i,n) for(i=1;i<n;i++)
	using namespace std;
	ll int multiply(ll int a,ll int b)
{
	ll int ans=(a%mod*b%mod)%mod;
	return ans;
}
ll int add(ll int a, ll int b)
{
	ll int ans=(a%mod+b%mod)% mod;	
	return ans;
}

	int power(ll int x,  ll int y, ll int p)  
{  
    ll int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}  
	void fastio()
	{					
		#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	    #endif
	    ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
	    cout.tie(NULL);

	}
	vector<ll int> adj[100001];
	ll int vis[100001]={0};
	ll int indegree[100001]={0};
	ll int dist[100001]={0};
	void dfs(ll int n)
	{
		vis[n]=1;
		for(auto node: adj[n])
		{
			dist[node]=max(dist[node],dist[n]+1);
			indegree[node]--;
			if (indegree[node]==0)
				dfs(node);
		}
	}
	ll int dp[100001]={0};
	void solve()
	{
		ll int n,k;
		cin>>n>>k;
		ll int a[n],i,j;
		rep(i,n)
		cin>>a[i];
		for(i=1;i<=k;i++)
		{
			rep(j,n)
			{
				if (i-a[j]>=0 && dp[i-a[j]]==0)
					dp[i]=1;
					
			}
		}
		// cout<<dp[0]<<endl;
		if (dp[k])
			cout<<"First"<<endl;
		else
			cout<<"Second"<<endl;

		
    }
	int main()
	{
		fastio();
		ll int t;
		t=1;
		// cin>>t;
		
		while(t--)
		{
			solve();
		}
			
	}
			