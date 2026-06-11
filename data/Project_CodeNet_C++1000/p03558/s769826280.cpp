#include <iostream>
#include <cstdio>
#include <deque>
#define int long long
using namespace std;
bool vis[100005];
signed main() {
	int n; cin >> n;
	deque<pair<int, int> > q; q.push_front(make_pair(1, 1));
	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop_front();
		if (vis[p.first]) continue; vis[p.first] = 1;
		if (!p.first) { cout << p.second << endl; return 0; }
		q.push_front(make_pair((p.first * 10) % n, p.second));
		q.push_back(make_pair((p.first + 1) % n, p.second + 1));
	}
	return 0;
}