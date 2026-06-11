#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;
struct edge {int to, cost;};
const int INF = 1001001001;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<edge>> g(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			int c;
			cin >> c;
			g[j].push_back(edge{i, c});
		}
	int d1[10];

	fill(d1, d1+10, INF);
	d1[1] = 0;
	priority_queue<P, vector<P>, greater<P>> pque;
	pque.push(P(0, 1));
	while (!pque.empty()) {
		P p = pque.top(); pque.pop();
		int v = p.second;
		if (p.first > d1[v]) continue;
		for (edge e : g[v]) {
			if (d1[e.to] > d1[v] + e.cost) {
				d1[e.to] = d1[v] + e.cost;
				pque.push(P(d1[e.to], e.to));
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			int a;
			cin >> a;
			if (a == -1) continue;
			ans += d1[a];
		}
	cout << ans << endl;
	return 0;
}