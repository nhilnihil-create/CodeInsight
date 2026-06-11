#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

vector<pair<int, int>> adj[100000];
int pos[100000];

void dfs(int c, int p)
{
	pos[c] = p;
	for (auto n : adj[c]) {
		if (pos[n.first] == 0x7f7f7f7f) {
			dfs(n.first, p + n.second);
		}
		else if (pos[n.first] != pos[c] + n.second) {
			cout << "No\n";
			exit(0);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int N, M;
	for (cin >> N >> M; M; M--) {
		int l, r, d;
		cin >> l >> r >> d;
		adj[--l].push_back({ --r,d });
		adj[r].push_back({ l,-d });
	}
	memset(pos, 0x7f, sizeof(pos));
	for (int i = 0; i < N; i++) if (pos[i] == 0x7f7f7f7f) {
		dfs(i, 0);
	}
	cout << "Yes\n";
	return 0;
}