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

const int MAXN = 300 * 1000 + 10, MOD = 998244353;
int fact[MAXN];

int pw(int a, int b) {
	long long ans = 1;
	for(int i = 63; i >= 0; i --) {
		ans *= ans;
		ans %= MOD;
		if((b >> i) & 1)
			ans *= a;
		ans %= MOD;
	}
	return ans;
}

int rev(int a)
{
	return pw(a, MOD - 2);
}

int choose(int nn, int kk)
{
	return fact[nn] * rev(fact[kk]) % MOD * rev(fact[nn - kk]) % MOD;
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, a, b, k;
	cin >> n >> a >> b >> k;

	fact[0] = 1;
	for (int i = 1; i <= n; i ++)
		fact[i] = fact[i - 1] * i % MOD;

	int ans = 0;
	for (int i = 0; i <= n; i ++)
	{
		if((k - i * a) % b || k - i * a < 0 || (k - i * a) / b > n)
			continue;
		ans += choose(n, i) * choose(n, (k - i * a) / b) % MOD;
		ans %= MOD;
	}
	cout << ans << "\n";

	return 0;
}




