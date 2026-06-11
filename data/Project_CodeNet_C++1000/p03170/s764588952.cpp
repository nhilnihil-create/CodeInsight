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


void solve()
{
    ll n, k, i, j, ans;
	cin >> n>>k;

	ll a[n];

	for (i = 0; i < n; i++)
		cin >> a[i];

	vector<ll> dp(k + 1, 0);

	for (i = 1; i <= k; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i - a[j] >= 0 && dp[i - a[j]] == 0)
			{
				dp[i] = 1;
				break;
			}
		}
	}

	if (dp[k] == 0)
		cout << "Second" << endl;
	else
		cout << "First" << endl;
}

