#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
using namespace std;

typedef long long ll;



int main() {
	int k; cin >> k;
	vector<pair<double, ll>> can;
	for (ll i = 0; i <= 12; i++) {
		ll p = 0, q = 1;
		for (ll j = 0; j < i; j++) p = 10*p + 9, q *= 10;
		for (ll a = 0; a <= 9; a++) {
			for (ll b = 0; b <= 9; b++) {
				for (ll c = 0; c <= 9; c++) {
					ll v = (100 * a + 10 * b + c)*q + p;
					can.push_back({ (double)v / (double)(a + b + c + 9 * i), v });
				}
			}
		}
	}
	sort(can.begin(), can.end());
	ll ma = 0;
	int cnt = 0;
	for (auto p : can) {
		ll a = p.second;
		if (a <= ma) continue;
		cout << a << endl;
		ma = a;
		cnt++;
		if (cnt >= k) break;
	}
	return 0;
}