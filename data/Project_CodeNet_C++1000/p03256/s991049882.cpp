#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
using ll = long long;
const ll MOD = 1000000007;

vector<int> G[200010];
int ABC[200010][2];
bool er[200010];

int main() {
	for (int i = 0;i < 200010;i++)ABC[i][0] = ABC[i][1] = er[i] = 0;
	int N, M, a, b;
	cin >> N >> M;
	string S;
	cin >> S;
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	queue<int> Q;
	for (int i = 0;i < N;i++) {
		for (int x : G[i]) {
			if (S[x] == 'A') {
				ABC[i][0]++;
			}
			if (S[x] == 'B') {
				ABC[i][1]++;
			}
		}
		if (ABC[i][0] == 0 || ABC[i][1] == 0) {
			Q.push(i);
			er[i] = 1;
		}
	}
	bool ab = 0;
	while (!Q.empty()) {
		a = Q.front();
		Q.pop();
		if (S[a] == 'A')ab = 0;
		else ab = 1;
		for (int x : G[a]) {
			ABC[x][ab]--;
			if (ABC[x][ab] == 0 && !er[x]) {
				Q.push(x);
				er[x] = 1;
			}
		}
	}
	for (int i = 0;i < N;i++) {
		if (!er[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}