#include<bits/stdc++.h>
using namespace std;
#define vb __int128
#define ll long long
#define ld long double
#define full(a) a.begin(),a.end()
#define stoink stack<ll>
#define vec vector <ll>
#define vg vector<vector<ll> >
#define vgw vector<vector<pair<ll,ll> >
#define pa pair<ll,ll>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pre 0.00000000000000000001
#define inf 1000000000000
#define mod 998244353
vector<vector<vector<ld>>> dp;
ll n;
ld func(ll a,ll b,ll c) {
	if(a + b + c == 0)
		return 0;
	if(dp[a][b][c] > -0.5)
		return dp[a][b][c];
	ld res = (ld)n / (ld)(a + b + c);
	if(c > 0)
		res += func(a,b+1,c-1) * (ld)c / (ld)(a + b + c);
	if(b > 0)
		res += func(a+1,b-1,c) * (ld)b / (ld)(a + b + c);
	if(a > 0)
		res += func(a-1,b,c) * (ld)a / (ld)(a + b + c);
	return dp[a][b][c] = res;
}
int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vec arr(n);
	dp.resize(n+1,vector<vector<ld>>(n+1,vector<ld>(n+1,-1)));
	ll onc = 0,twoc = 0,threec = 0;
	for(int i = 0 ; i < n ; i++) {
		cin >> arr[i];
		if(arr[i] == 1)
			onc++;
		else if(arr[i] == 2)
			twoc++;
		else 
			threec++;
	}
	cout << fixed << setprecision(12) << func(onc,twoc,threec);
	return 0;
}