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
#define endl "\n"
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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	t = 1;

	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

vector<vector<ll>> dp(3005, vector<ll>(3005, -1));

string LCS(string &s1, string &s2, ll l)
{
	string ans = "";
	ll i = 0 , j = 0;

	while (l > 0)
	{
		if (s1[i] == s2[j])
		{
			ans += s1[i];
			i++;
			j++;
			l--;
		}
		else if (dp[i + 1][j] > dp[i][j + 1])
		{
			i++;
		}
		else
			j++;
	}

	return ans;
}

ll calc(string &s1, string &s2, ll i, ll j)
{
	if (i >= s1.size() || j >= s2.size())
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (s1[i] == s2[j])
	{
		return dp[i][j] = 1 + calc(s1, s2, i + 1, j + 1);
	}

	return dp[i][j] = max(calc(s1, s2, i, j + 1), calc(s1, s2, i + 1, j));
}

void solve()
{
	ll n, m, len;
	string s1, s2, s;
	cin >> s1 >> s2;

	n = s1.size();
	m = s2.size();

	len = calc(s1, s2, 0, 0);

	s = LCS(s1, s2, len);
	cout << s << endl;

}
