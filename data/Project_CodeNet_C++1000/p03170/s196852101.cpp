#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
ll a[N+5];
ll dp[2][N+5];

bool rec(ll player,ll n,ll k)
{
	bool ans = 1;
	if(dp[player][k]!=-1)
		return dp[player][k];
	for(ll i=1;i<=n;i++)
	{
		if(k>=a[i])
			ans =ans & rec((player+1)%2,n,k-a[i]);
	}
	dp[player][k] = !ans;
	return !ans;
}

bool fun(ll player, ll n, ll k){
	if(dp[player][k]!=-1){
		return dp[player][k];
	}
	bool ans = true;
	for(ll i=1;i<=n;i++){
		ans = ans & fun((player+1)%2, n,k-a[i]);
	}
	return dp[player][k] = !ans;
}

int main()
{
    IO
	clock_t begin = clock();
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<=k;i++)
    	dp[0][i] = dp[1][i] = -1;
    for(ll i=1;i<=n;i++)
    	cin>>a[i];
    bool final_ans = rec(1,n,k);
    // cout<<final_ans<<endl;
    if(final_ans==1)
    	cout<<"First";
    else
    	cout<<"Second";
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}