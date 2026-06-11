# include<bits/stdc++.h>
 
using namespace std;
 
# define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<ll, ll> pll;
 
# define S second
# define F first
# define kill(x) return(cout << x << endl, 0LL)
# define debug(x) cerr<< #x << " : " << x << endl
# define ddebug(x, y) cerr<< #x << " : " << x  << ", " << #y << " : " << y << endl
# define sz(s) (int)s.size()
# define sq(x) (x) * (x)
# define PB(x) push_back(x)
# define smax(x, y) (x) = max((x), (y))
# define smin(x, y) (x) = min((x), (y))
# define all(x) x.begin(), x.end()
# define SP fixed << setprecision(10)
# define MP make_pair
 
const int MAXN = 100 * 1000 + 10;
string a[MAXN];
 
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	int n;
	cin >> n;
 
	cout << 0 << endl;
	cin >> a[0];
	if (a[0] == "Vacant")
		return 0;
	a[n] = a[0];
 
	int l = 0, r = n;
	while (true)
	{
		int mid = (l + r) / 2;
		cout << mid << endl;
		cin >> a[mid];
		if (a[mid] == "Vacant")
			return 0;
 
		if (a[l] == a[r])
		{
			if ((a[mid] == a[l]) ^ ((mid - l) & 1 ^ 1))
				r = mid;
			else
				l = mid;
		}
		else
		{
			if (((mid - l) & 1 ^ 1) ^ (a[mid] == a[l]))
				r = mid;
			else
				l = mid;
		}
	}
 
	return 0;
}
