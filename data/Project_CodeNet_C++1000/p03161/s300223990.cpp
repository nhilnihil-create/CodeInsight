#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pie 3.142857143
#define ll long long int
#define fr(i,a,n) for(ll i=a;i<n;i++)
#define vi vector<int>
#define vlli vector<ll>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fv(i,a) for(auto i:a)
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define frv(i,c) for(auto i = c.begin(); i != c.end(); i++)

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n];
	fr(i, 0, n)
	cin >> a[i];
	vlli d(n, INT_MAX);
	d[0] = 0;
	fr(i, 0, n)
	{
		fr(j, i + 1, i + k + 1)
		{
			if (j < n)
			{
				d[j] = min(d[j], d[i] + abs(a[j] - a[i]));
			}
		}
	}
	cout << d[n - 1] << endl;


}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	//cin>>t;
	t = 1;
	while (t--)
	{
		solve();
	}


	return 0;
}