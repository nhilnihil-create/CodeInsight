#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>a(N + 1);
	vector<int>b(N + 1);
	vector<vector<int>>edge(N + 1);
	string s;
	cin >> s;
	vector<int>can(N + 1, 1);
	can[0] = 0;
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		edge[L].push_back(R);
		edge[R].push_back(L);
		if (s[L - 1] == 'B')b[R]++;
		else a[R]++;
		if (s[R - 1] == 'B')b[L]++;
		else a[L]++;
	}
	queue<int>Q;
	for (int i = 1; i <= N; i++) {
		if (a[i] && b[i])continue;
		Q.push(i);
		can[i] = false;
	}
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (!can[i])continue;
			if (s[cn-1] == 'B') {
				b[i]--;
			}
			else {
				a[i]--;
			}
			if (a[i] && b[i])continue;
			Q.push(i);
			can[i] = 0;
		}
	}
	int ans = 0;
	for (auto i : can)ans += i;
	if (ans)cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
