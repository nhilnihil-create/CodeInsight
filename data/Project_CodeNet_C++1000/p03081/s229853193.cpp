# include<bits/stdc++.h>
 
using namespace std;

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
# define UB upper_bound

const int MAXN = 200 * 1000 + 10;
int n, q;
char c[MAXN], s[MAXN];
bool d[MAXN];

bool dead(int ind)
{
	for (int i = 0; i < q; i ++)
	{
		if (c[i] == s[ind])
			ind += (d[i] ? +1 : -1);
		if (ind < 0)
			return true;
	}
	return false;
}

int bs()
{
	int l = 0, r = n + 1;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (dead(mid - 1))
			l = mid;
		else
			r = mid;
	}
	return l;
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for (int i = 0; i < n; i ++)
		cin >> s[i];
	for (int i = 0; i < q; i ++)
	{
		char cc;
		cin >> c[i] >> cc;
		d[i] = (cc == 'R');
	}

	int ans1 = bs();
	reverse(s, s + n);
	for (int i = 0; i < q; i ++)
		d[i] ^= 1;
	int ans2 = bs();

	cout << n - min(ans1 + ans2, n) << endl;

	return 0;
}
