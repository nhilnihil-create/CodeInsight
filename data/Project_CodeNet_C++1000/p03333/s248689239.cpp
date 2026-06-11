#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 2 + 10, INF = 1e9 * 1e5;

vector<bool> used;
vector<pair<ll, ll>> vec;
vector<tuple<ll, ll, ll>> vec1, vec2;

int main()
{
	fastInp;

	ll n;
	cin >> n;

	ll x = 0;
	for (int i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;
		vec.push_back({ l, r });
		vec1.push_back({ l, r, i });
		vec2.push_back({ r, l, i });
	}

	sort(vec1.rbegin(), vec1.rend());
	sort(vec2.begin(), vec2.end());

	used.resize(n);
	ll i = 0, i2 = 0, ans = 0;
	while (i < vec1.size() && i2 < vec2.size()) {
		while ((i < vec1.size()) && used[get<2>(vec1[i])]) {
			i++;
		}
		while ((i2 < vec2.size()) && used[get<2>(vec2[i2])]) {
			i2++;
		}
		if (!(i < vec1.size() && i2 < vec2.size())) break;
		if (get<0>(vec1[i]) - x > x - get<0>(vec2[i2])) {
			if (get<0>(vec1[i]) - x > 0) {
				ans += get<0>(vec1[i]) - x;
				x = get<0>(vec1[i]);
			}
			used[get<2>(vec1[i])] = 1;
		}
		else {
			if (x - get<0>(vec2[i2]) > 0) {
				ans += x - get<0>(vec2[i2]);
				x = get<0>(vec2[i2]);
			}
			used[get<2>(vec2[i2])] = 1;
		}
	}

	ll a = abs(x) + ans, a2 = 0;
	used.resize(0);
	used.resize(n);
	i = 0, i2 = 0, ans = 0, x = 0;
	while (i < vec1.size() && i2 < vec2.size()) {
		while ((i < vec1.size()) && used[get<2>(vec1[i])]) {
			i++;
		}
		while ((i2 < vec2.size()) && used[get<2>(vec2[i2])]) {
			i2++;
		}
		if (!(i < vec1.size() && i2 < vec2.size())) break;
		if (i == 0 && i2 == 0) {
			if (get<0>(vec1[i]) - x < x - get<0>(vec2[i2])) {
				if (get<0>(vec1[i]) - x > 0) {
					ans += get<0>(vec1[i]) - x;
					x = get<0>(vec1[i]);
				}
				used[get<2>(vec1[i])] = 1;
			}
			else {
				if (x - get<0>(vec2[i2]) > 0) {
					ans += x - get<0>(vec2[i2]);
					x = get<0>(vec2[i2]);
				}
				used[get<2>(vec2[i2])] = 1;
			}
		}
		else {
			if (get<0>(vec1[i]) - x > x - get<0>(vec2[i2])) {
				if (get<0>(vec1[i]) - x > 0) {
					ans += get<0>(vec1[i]) - x;
					x = get<0>(vec1[i]);
				}
				used[get<2>(vec1[i])] = 1;
			}
			else {
				if (x - get<0>(vec2[i2]) > 0) {
					ans += x - get<0>(vec2[i2]);
					x = get<0>(vec2[i2]);
				}
				used[get<2>(vec2[i2])] = 1;
			}
		}
	}

	cout << max(a, ans + abs(x));
	return 0;
}