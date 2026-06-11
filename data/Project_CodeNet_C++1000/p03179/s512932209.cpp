#include<bits/stdc++.h>
#define ll long long
#define dl double
using namespace std;

//***********************************************************************
int MAXNUM = 5e3+5;
vector <int>vis(MAXNUM);
vector<int> pr;
void sieve() {
	pr.push_back(2);
	for(ll i=3;i<MAXNUM;i+=2) if(!vis[i]) {
		pr.push_back(i);
		for(ll j=i*i;j<MAXNUM;j+=2*i) vis[j]=true;
	}
}
//************************************************************************
ll mod=1000000007;
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >>s;
    vector<vector<ll>> dp(n);
    for(ll i=0;i<n;i++)
    {
        dp[i].resize(n+1);

    }
    //cout << "check" << endl;
    if(s[0]=='<')
    {
        dp[1][1]=0;
        dp[1][2]=1;
    }
    else
    {
        dp[1][1]=1;
        dp[1][2]=1;
    }
    //cout << dp[1][1] << " " << dp[1][2] << endl;
    for(int i=2;i<n;i++)
    {
        for(int j=1;j<=i+1;j++)
        {
            ll add=0;
            if(s[i-1]=='>')
            {
                add=(dp[i-1][i]-dp[i-1][j-1]+mod)%mod;
            }
            else
            {
                add=dp[i-1][j-1];
            }
            dp[i][j]=(dp[i][j-1]+add)%mod;
          //  cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[n-1][n] << endl;
	
}


int main()
{ 
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	ll t;
	//cin >> t;
	t=1;
	while(t--)
	{
		solve();
	}

	return 0;
}