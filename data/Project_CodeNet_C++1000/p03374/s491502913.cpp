#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

#include <bits/stdc++.h>
using namespace std;

const ll mod = 1e9 + 7;

const ll INF = 1e15;

int main() {
	ll n, c;
	cin >> n >> c;
	vector<ll> xs(n,0);
	vector<ll> vs(n,0);
	rep(i, n) {
		cin >> xs[i];
		cin >> vs[i];
	}
	vector<ll> left(n + 1, 0);
	vector<ll> right(n + 1, 0);
	rep(i, n) {
		left[i + 1] = left[i] + vs[i];
		right[i + 1] = right[i] + vs[n-1-i];
	}
	ll u = 0;
	rep(i, n) {
		u = max(u, left[i + 1] - xs[i]);
		u = max(u, right[i + 1] - c + xs[n-1-i]);
	}
	{
		map<ll, ll> ms;
		rep(i, n) {
			ms[left[i + 1] - xs[i]]++;
		}
		rep(i, n) {
			auto key = left[n - i] - xs[n-i-1];
			ms[key]--;
			if (!ms[key]) {
				ms.erase(key);
			}
			ll a = 0;
			if (ms.size()) {
				a = ms.rbegin()->first;
			}
			auto add = right[i + 1] - 2 *(c - xs[n - 1 - i]);
			a += add;
			u = max(u, a);
		}
	}

	{
		map<ll, ll> ms;
		rep(i, n) {
			ms[right[i + 1] - c + xs[n - 1 - i]]++;
		}
		rep(i, n) {
			auto key = right[n - i] - c + xs[i];
			ms[key]--;
			if (!ms[key]) {
				ms.erase(key);
			}
			ll a = 0;
			if (ms.size()) {
				a = ms.rbegin()->first;
			}
			auto add = left[i + 1] - 2 * (xs[i]);
			a += add;
			u = max(u, a);
		}
	}
	cout << u << endl;
	return 0;
}
