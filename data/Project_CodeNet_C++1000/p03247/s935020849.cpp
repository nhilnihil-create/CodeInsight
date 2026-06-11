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
#define MOD 1000000007 
#define INF 1000000000000000000
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing
#define int ll
int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
signed main() {
	int n;
	cin >> n;
	vector <int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if(abs(x[i] + y[i]) % 2 != abs(x[0] + y[0]) % 2) {
			cout << -1;
			return 0;
		}
	}
	vector <int> v;
	for (int i = 30; i >= 0; i--) {
		v.push_back(1 << i);
	}
	if((x[0] + y[0]) % 2 == 0) {
		v.push_back(1);
	}
	cout << (int) v.size() << "\n";
	for (auto g: v)
		cout << g << " ";
	cout << "\n";
	string moves = "LRUD";
	vector <int> l({-1, 1, 0, 0});
	vector <int> r({0, 0, 1, -1});
	for (int i = 0; i < n; i++) {
		int cx = 0, cy = 0;
		string ans;
		for (auto g : v) {
			int mn = INF, p = -1;
			for (int j = 0; j < 4; j++) { 
				int tx = cx + g * l[j];
				int ty = cy + g * r[j];
				int d = dist(tx, ty, x[i], y[i]);
				if(d < mn) mn = d, p = j;
			}
			cx += g * l[p];
			cy += g * r[p];
			ans += moves[p];
		}
		cout << ans << "\n";
	}
}
