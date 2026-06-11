#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Pi pair<int,int>
#define Pl pair<ll,ll>
#define all(V) V.begin(),V.end()
const ll MOD = 1000000007;

vector<vector<Pi>> X(100000);
vector<int> W(100000, MOD);

int dest, dist;

bool search(int x, int y) {
	int ss = X[x].size();
	int f, s;
	for (int i = 0;i < ss;i++) {
		f = X[x][i].first;
		s = X[x][i].second;
		if (f == y) continue;
		if (W[f] == MOD) {
			W[f] = W[x] + s;
			if (search(f, x))
				return true;
		}
		else if (W[f] != W[x] + s)
			return true; //失敗
	}
	return false;
}

int main() {
	int N, M;
	cin >> N >> M;
	int L, R, D;
	for (int i = 0;i < M;i++) {
		cin >> L >> R >> D;
		L--;R--;
		X[L].push_back({ R,D });
		X[R].push_back({ L,-D });
	}
	for (int i = 0;i < N;i++) {
		if (W[i] == MOD) {
			if (search(i, MOD)) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}