#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)

int num[100000+1];
int main() {
	int N, M; cin >> N >> M;
	vector<P> v(M), b(M);
	rep(i, M) {
		cin >> v[i].first >> v[i].second;
		b[i] = v[i];
		num[v[i].first]++;
	}
	rep(i, 100000+1) {
		if (i == 0) continue;
		num[i] += num[i-1];
	}
	sort(v.begin(), v.end());
	rep(i, M) {
		auto it = lower_bound(v.begin(), v.end(), b[i]);
		int idx = distance(v.begin(), it) + 1;
		idx -= num[b[i].first - 1];
		char s[7];
		sprintf(s, "%d", b[i].first);
		for (int i = 0; i < 6 - strlen(s); i++) {
			cout << "0";
		}
		cout << b[i].first;
		sprintf(s, "%d", idx);
		for (int i = 0; i < 6 - strlen(s); i++) {
			cout << "0";
		}
		cout << idx << endl;
	}
}