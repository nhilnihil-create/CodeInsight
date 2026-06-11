#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 2e5 + 100;

int n, m, u, v, d[N][2];
bool done[N];
string s;
queue<int> q;
vector<pii> nei[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> s;
	while(m--) {
		cin >> u >> v;
		int c = (s[--u] == s[--v]);
		nei[u].push_back(pii(v, c));
		nei[v].push_back(pii(u, c));
	}
	for (int i = 0; i < n; i++)
		for (pii p: nei[i])
			d[i][p.second]++;
	for (int i = 0; i < n; i++)
		if(d[i][0] == 0 || d[i][1] == 0) {
			q.push(i);
			done[i] = true;
		}
	while(q.size()) {
		n--;
		v = q.front();
		q.pop();
		done[v] = true;
		for (pii p: nei[v]) {
			d[p.first][p.second]--;
			if(done[p.first] == false && (d[p.first][0] == 0 || d[p.first][1] == 0)) {
				done[p.first] = true;
				q.push(p.first);
			}
		}
	}
	cout << (n? "Yes": "No");
	return 0;
}