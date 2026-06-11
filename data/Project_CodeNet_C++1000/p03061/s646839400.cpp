/***** author :  C0d1ngPhenomena *****/

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define TestCases int T; cin>>T; while(T--)
#define rep(i,a,b) for(ll i = a; i < b; i++)
#define revrep(i,a,b) for(ll i = b-1; i >= a; i--)
#define vll vector<ll>
#define vvll vector < vll >
#define pll pair<ll, ll>
#define vpll vector <pll>
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define alld(c) c.begin(),c.end(),greater<int>()
#define mem(a,val) memset(a,val,sizeof(a))
#define f first
#define s second
#define pb push_back
using namespace std;

const int maxn = 1e5 + 5;

int n, x[maxn], pref[maxn], suff[maxn];

ll calcgcd(ll a, ll b)
{
	if (!a)
		return b;

	return calcgcd(b % a, a);
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	rep(i, 1, n + 1)
	cin >> x[i];

	rep(i, 1, n + 1)
	pref[i] = calcgcd(pref[i - 1], x[i]);

	revrep(i, 1, n + 1)
	suff[i] = calcgcd(suff[i + 1], x[i]);

	// rep(i, 1, n + 1)
	// cout << pref[i] << " ";
	// cout << endl;
	// rep(i, 1, n + 1)
	// cout << suff[i] << " ";

	cout << endl;

	ll ans = 1;

	rep(i, 1, n + 1)
	{
		// cout << ans << " " <<  calcgcd(pref[i - 1], suff[i + 1]) << endl;
		ans = max(ans, calcgcd(pref[i - 1], suff[i + 1]));
	}

	cout << ans << endl;

	return 0;
}






