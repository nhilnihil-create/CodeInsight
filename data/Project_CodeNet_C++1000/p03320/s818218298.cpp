#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

int main() {
	auto sum_d = [&] (ll n) {
		int res = 0;
		while(n != 0) {
			res += n % 10;
			n /= 10;
		}
		return 1.0 * res;
	};
	//const int N = 19999999 + 1;
	//vector <double> vv(N);
	//for (int i = 1; i < N; i++) {
		//vv[i] = 1.0 * i / sum_d(i);
	//}
	//vector <ll> ans1;
	//double mn1 = INF;
	//for (int i = (int) vv.size() - 1; i >= 1; i--) {
		//if(vv[i] <= mn1) {
			//mn1 = vv[i];
			//ans1.push_back(i);
		//}
	//}
	//reverse(all(ans1));
	
	auto power10 = [&] (int n) {
		ll res = 1;
		for (int i = 0; i < n; i++)
			res = res * 10;
		return res;
	};
	vector <pair<double, ll>> v;
	for (int i = 1; i <= 9; i++) {
		v.emplace_back(i / sum_d(i), i);
	}
	for (int i = 1; i <= 9; i++) {
		v.emplace_back((10 * i + 9) / sum_d(10 * i + 9), 10 * i + 9);
	}
	for (int i = 1; i <= 9; i++) {
		v.emplace_back((v.back().ss + 100) / sum_d(v.back().ss + 100), v.back().ss + 100);
	}
	int n = 16;
	for (int i = 4; i < n; i++) {
		if(n <= 5) {
			ll nines = power10(i - 2) - 1;
			for (int j = 10; j <= 99; j++) {
				ll x = j * power10(i - 2) + nines;
				v.emplace_back(x / (1.0 * sum_d(x)), x);
			}
		}
		else {
			ll nines = power10(i - 3) - 1;
			for (int j = 100; j <= 999; j++) {
				ll x = j * power10(i - 3) + nines;
				v.emplace_back(x / (1.0 * sum_d(x)), x);
			}
		}
	}
	//for (auto g : v) {
		//cout << g.ss << "\n";
	//}
	vector <ll> ans;
	double mn = INF;
	for (int i = (int) v.size() - 1; i >= 0; i--) {
		if(v[i].ff <= mn) {
			mn = v[i].ff;
			ans.push_back(v[i].ss);
			//cout << v[i].ss << " " << mn << "\n";
		}
	}
	reverse(all(ans));
	//for (auto g : ans) {
		//cout << g << "\n";
	//}
	//for (int i = 0; i < (int) ans1.size(); i++) {
		//cerr << ans1[i] << " " << ans[i] << "\n";
		//assert(ans1[i] == ans[i]);
	//}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cout << ans[i] << "\n";
	}
}
