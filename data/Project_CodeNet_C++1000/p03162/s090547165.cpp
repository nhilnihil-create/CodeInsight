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
	int n;
	cin >> n;
	vi d(3, 0);

	fr(t, 0, n)
	{
		int a[3];
		fr(i, 0, 3)
		cin >> a[i];
		vi x(3, 0);

		fr(j, 0, 3)
		{
			fr(k, 0, 3)
			{
				if (k != j)
				{
					x[j] = max(x[j], a[j] + d[k]);
				}
			}
		}
		d = x;
	}
	int l = 0;
	fr(i, 0, 3)
	{
		l = max(l, d[i]);
	}
	cout << l << endl;

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