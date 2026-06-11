#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define MOD 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(var) (var).begin(), (var).end()
#define MAXX 9000000000000000000
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> > 
#define vvpi vector<vector<pair<int,int> > >

int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,i,a[100005],pre[100005],suf[100005];
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}

	pre[0] = a[0];
	for(i=1;i<n;i++)
	{
		pre[i] = gcd(pre[i-1], a[i]);
	}

	int ans = pre[n-2];

	suf[n-1] = a[n-1];

	for(i=n-2;i>=0;i--)
	{
		suf[i] = gcd(suf[i+1], a[i]);
	}

	ans = max(ans, suf[1]);
	
	for(i=1;i<n-1;i++)
	{
		int x = gcd(pre[i-1], suf[i+1]);
		ans = max(ans, x);
	}

	cout << ans;
	
	return 0;
}