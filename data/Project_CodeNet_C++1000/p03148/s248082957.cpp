#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
#include <functional>
//#include <boost/multiprecision/cpp_int.hpp>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)
#define llrep(i, n) for(ll i = 0; i < n; ++i)
#define llREP(i, m, n) for(ll i = m; i < n; ++i)
#define llrrep(i,n) for(ll i = n; i >= 0; --i)
#define llRREP(i, m, n) for(ll i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
using pil = std::pair<int, long long>;
using pli = std::pair<long long, int>;
using plpii = std::pair<long long, std::pair<int, int>>;
using pdd = std::pair<double, double>;

const long long INF = 1000000000000000001;
const long long _MOD = 1000000007;
const long long MOD = 998244353;
const int ALPHABET = 27;
const double pi = 3.14159265358979;

using namespace std;
//namespace mp = boost::multiprecision;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	pll* dt = new pll[n];
	rep(i, n) cin >> dt[i].second >> dt[i].first;
	sort(dt, dt + n);

	ll ans = 0, kk;
	map<ll, int> kind;
	deque<ll> stack;
	rep(i, k) {
		ans += dt[n - 1 - i].first;
		if (kind[dt[n - 1 - i].second] != 0) {
			stack.push_front(dt[n-1-i].first);
		}
		kind[dt[n - 1 - i].second] = 1;
	}
	 kk= kind.size()*kind.size();

	int x = n - 1 - k;
	ll sum = ans;
	ll _kk = 0;
	while (!stack.empty()) {
		if (x >= 0) {
			bool flag = false;

			sum -= stack.front();
			stack.pop_front();
			for (x; x >= 0; --x) {
				if (kind[dt[x].second] == 0) {
					kind[dt[x].second] = 1;
					sum += dt[x].first;
					_kk = kind.size()*kind.size();
					
					flag = true;
					break;
				}
			}

			if (flag) {
				if (ans + kk < sum + _kk) {
					ans = sum;
					kk = _kk;
				}
			}
		}
		else {
			break;
		}
	}

	cout << ans+kk << "\n";

	return 0;
}
