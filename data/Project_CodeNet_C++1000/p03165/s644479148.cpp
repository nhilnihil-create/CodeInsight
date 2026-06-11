#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
ll dp[3001][3001];
vector <char> V;
void fun(ll idx1,ll idx2,string S1,string S2)
{
	if(idx1==0 || idx2==0)
		return;
	if(dp[idx1][idx2] == (1+dp[idx1-1][idx2-1]) && S1[idx1]==S2[idx2])
	{
		V.push_back(S1[idx1]);
		fun(idx1-1,idx2-1,S1,S2);
	}
	else if(dp[idx1][idx2] == dp[idx1-1][idx2])
		fun(idx1-1,idx2,S1,S2);
	else
		fun(idx1,idx2-1,S1,S2);
	return;
}

int main()
{
    IO
	clock_t begin = clock();
    string s1,s2,S1,S2;
    cin>>s1>>s2;
    S1 = "$" + s1;
    S2 = "$" + s2;
    ll n = s1.size(),m = s2.size();
    for(ll i=0;i<=n;i++)
    {
    	for(ll j=0;j<=m;j++)
    		dp[i][j] = 0;
    }
    for(ll i=1;i<=n;i++)
    {
    	for(ll j=1;j<=m;j++)
    	{
    		dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
    		if(S1[i]==S2[j])
    			dp[i][j] = max(dp[i][j],1+dp[i-1][j-1]);
    	}
    }
    fun(n,m,S1,S2);
    reverse(V.begin(),V.end());
    for(auto it:V)
    	cout<<it;
    cout<<endl;
    // cout<<dp[n][m]<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}