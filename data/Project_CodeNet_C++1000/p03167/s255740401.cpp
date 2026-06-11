	#include <bits/stdc++.h>
	#include <set>
	#define ll long long 
	#include <string>
	#define pb push_back
	#define mp make_pair
	# define pi 3.14159265358979323846
	#define mod 1000000007
    #define rep(i,n) for(i=0;i<n;i++)
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
	void solve()
	{
		ll int h,w,i,j;
		cin>>h>>w;
		char ch[h][w];
		rep(i,h)
		rep(j,w)
		cin>>ch[i][j];
		ll int dp[h][w];
		memset(dp,0,sizeof dp);
		dp[h-1][w-1]=1;
		// rep(i,h){rep(j,w)cout<<dp[i][j]<<" ";
		// cout<<endl;}
		for(i=w-2;i>=0;i--)
		{
			if (ch[h-1][i]=='#')
				dp[h-1][i]=0;
			else
			{
				dp[h-1][i]=add(dp[h-1][i+1],dp[h-1][i]);
			}
		}
		// rep(i,h){rep(j,w)cout<<dp[i][j]<<" ";
		// cout<<endl;}
		for(i=h-2;i>=0;i--)
		{
			if (ch[i][w-1]=='#')
				dp[i][w-1]=0;
			else
			{
				dp[i][w-1]=add(dp[i][w-1],dp[i+1][w-1]);
			}
		}
		for(i=h-2;i>=0;i--)
		{
			for(j=w-2;j>=0;j--)
				{
					if (ch[i][j]=='#')
				dp[i][j]=0;
			else{
					ll int op1=dp[i+1][j];
					ll int op2=dp[i][j+1];
					dp[i][j]=(op1+op2)%mod;}
				}
		}
		// rep(i,h){rep(j,w)cout<<dp[i][j]<<" ";
		// cout<<endl;}
		cout<<dp[0][0]<<endl;


		
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
			