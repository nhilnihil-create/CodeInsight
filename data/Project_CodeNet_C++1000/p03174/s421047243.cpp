#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define inf 1e9
typedef pair<int,int> pii;
typedef pair <long long,long long> pll;
typedef long long ll; 
typedef long double ld; 
const ll mod = 1e9+7;

ll dp[22][(1<<22)];
int solve(vector<vector <int> > &comp, int i , int womenSubs , int n )
{
    if(i == n+1)
	{	if(womenSubs == 0)
			return 1;
		else
			return 0;
	}
	if(dp[i][womenSubs] != -1)
		return dp[i][womenSubs];
	ll ans = 0;
	for(int w = 0; w < n; w++)
	{	bool avail = (((1<<w)&(womenSubs)) == 0) ? 0 : 1;
		if(avail && comp[i][w+1])
		{
			ans = (ans + solve(comp, i+1 , (womenSubs ^ (1<<w)), n)) % mod;
		}
	}
	return dp[i][womenSubs] = ans;
} 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector <vector <int>> comp(n+1, vector <int>(n+1));
	memset(dp , -1, sizeof dp);
	for(int i = 1; i<= n; i++)
	{	for(int j = 1; j<= n; j++)
		{
			cin >> comp[i][j];
		}
	}
	cout << solve(comp,1 , ((1<<(n))-1) , n);
	return 0;
}
