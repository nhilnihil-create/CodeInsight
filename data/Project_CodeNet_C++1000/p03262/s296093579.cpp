#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define endl 		"\n"
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define trace(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
template <typename Arg1> void ZZ(const char* name, Arg1&& arg1) {std::cerr << name << " = " << arg1 << endl;}
template <typename Arg1, typename... Args>void ZZ(const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr(names + 1, ',');
	std::cerr.write(names, comma - names) << " : " << arg1;
	ZZ(comma, args...);
}
void fact(int gcd, vi &fac) {
	for (int i = 1; i * i <= gcd; i++) {
		if (i * i == gcd) {
			fac.pb(i);
		}
		else {
			if (gcd % i == 0) {
				fac.pb(i);
				fac.pb(gcd / i);
			}
		}
	}
}
bool check(int d, vi &a, int x) {
	rep(i, 0, a.size()) {
		int dist = abs(a[i] - x);
		if (dist % d == 0) {
			return true;
		}
	}
	return false;
}
void solve() {
	int n, x;
	cin >> n >> x;
	vi a(n);
	rep(i, 0, n)cin >> a[i];
	if (n == 1) {
		cout << abs(x - a[0]);
		return;
	}
	sort(all(a));
	vi dist;
	rep(i, 1, n) {
		dist.pb(a[i] - a[i - 1]);
	}
	int gcd = dist[0];
	rep(i, 1, dist.size()) {
		gcd = __gcd(gcd, dist[i]);
	}
	trace(gcd)
	vi fac;
	fact(gcd, fac);
	sort(all(fac));
	int d = 1;
	rep(i, 0, fac.size()) {
		if (check(fac[i], a, x)) {
			d = fac[i];
		}
	}
	cout << d;
}
int main() {
	fast_io;
	int t = 1;
	// cin>>t;
	while (t--) {
		solve();
	}
	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}