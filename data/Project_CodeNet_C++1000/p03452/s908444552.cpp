#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

vector<pair<int, int>> adj[100000];
int dist[100000];
bool chk[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int N, M, t, c;
	priority_queue<pair<int, int>> Q;
	for (cin >> N >> M; M; M--) {
		int l, r, d;
		cin >> l >> r >> d;
		adj[--l].push_back({ --r,d });
		chk[r] = true;
	}
	memset(dist, 0x7f, sizeof(dist));
	for (int i = 0; i < N; i++) if (!chk[i]) {
		dist[i] = 0;
		Q.push({ 0,i });
	}
	while (!Q.empty()) {
		tie(t, c) = Q.top();
		Q.pop();
		if (-t != dist[c]) continue;
		for (auto n : adj[c]) {
			if (dist[n.first] > dist[c] + n.second) {
				dist[n.first] = dist[c] + n.second;
				Q.push({ -dist[n.first],n.first });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (dist[i] == 0x7f7f7f7f) {
			cout << "No\n";
			return 0;
		}
		for (auto n : adj[i]) {
			if (dist[n.first] != dist[i] + n.second) {
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";
	return 0;
}