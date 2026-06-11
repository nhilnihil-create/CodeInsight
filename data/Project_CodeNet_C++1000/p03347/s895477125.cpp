# include<bits/stdc++.h>

using namespace std;

# define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<ll, ll> pll;

# define S second
# define F first
# define kill(x) return(cout << x << endl, 0)
# define debug(x) cerr<< #x << " : " << x << endl
# define ddebug(x, y) cerr<< #x << " : " << x  << ", " << #y << " : " << y << endl
# define sz(s) (int)s.size()
# define sq(x) (x) * (x)
# define PB(x) push_back(x)
# define smax(x, y) (x) = max((x), (y))
# define smin(x, y) (x) = min((x), (y))
# define all(x) x.begin(), x.end()
# define SP fixed << setprecision(10)

const int MAXN = 200 * 1000 + 10;
int a[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	
	int ans = 0, x = 0;
	for (int i = n - 1; i >= 0; i --)
	{
		if (x > a[i])
			kill(-1);
		if (x < a[i])
		{
			ans += a[i];
			x = a[i];
		}
		x --;
	}

	if (x != -1)
		kill(-1);

	cout << ans << endl;

	return 0;
}
