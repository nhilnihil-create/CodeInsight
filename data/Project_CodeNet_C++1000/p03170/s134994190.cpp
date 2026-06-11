#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(i,k) for(i=0;i<k;i++)
#define ALL(c) (c).begin(),(c).end()
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define SZ(x) (x).size();
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define em emplace_back
#define ulli unsigned long long int
#define INF 1e18
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
void solve();

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int main() {
	fastio;
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/

	int t;
	t=1;

    //cin>>t;
	while (t--)
	{
		solve();
	}
	return 0;
}

ll n;

ll mex(unordered_set<ll> &s)
{
	ll mex = 0;

	while (s.find(mex) != s.end())
		mex++;

	return mex;
}

ll grundy(ll a[], ll k, vector<ll> &dp)
{
	if (dp[k] != -1)
		return dp[k];

	unordered_set<ll> s;

	for (ll i = 0; i < n; i++)
	{
		if (k - a[i] >= 0)
			s.insert(grundy(a, k - a[i], dp));
	}

	if (s.empty())
		return dp[k] = 0;

	return dp[k] = mex(s);
}

void solve()
{
	ll k, i, ans;
	cin >> n>>k;

	ll a[n];

	for (i = 0; i < n; i++)
		cin >> a[i];

	vector<ll> dp(k + 1, -1);
	dp[0] = 0;
	ans = grundy(a, k, dp);

	if (ans == 0)
		cout << "Second" << endl;
	else
		cout << "First" << endl;

}
