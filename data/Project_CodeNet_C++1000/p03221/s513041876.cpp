#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <ctime>
#include <random>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-9
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;

struct city {
	int p, y, i;
};

bool operator<(city a, city b) {
	return a.y < b.y;
}

int main() {
	speed;
	int n, m, p, y;
	cin >> n >> m;
	vector<city>v(m);
	for (int i = 0; i < m; ++i) {
		cin >> v[i].p >> v[i].y;
		v[i].i = i;
	}
	sort(v.begin(), v.end());
	vector<string>ans(m);
	vector<int>cnt(n + 1, 1);
	for (int i = 0; i < m; ++i) {
		string ps = to_string(v[i].p);
		ps = string(6 - ps.size(), '0') + ps;
		string cs = to_string(cnt[v[i].p]);
		cs = string(6 - cs.size(), '0') + cs;
		ans[v[i].i] = ps + cs;
		cnt[v[i].p]++;
	}
	for (auto i : ans)
		cout << i << '\n';
}