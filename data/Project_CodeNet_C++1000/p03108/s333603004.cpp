#include <iostream>
#include <vector>

using namespace std;

long long root(long long x, vector<long long>& par) {
	if (par[x] < 0) return x;
	return par[x] = root(par[x], par);
}

long long size(long long x, vector<long long>& par) {
	return -par[root(x, par)];
}

int main() {
	long long N, M;
	cin >> N >> M;
	vector<pair<long long, long long>> E(M);
	for (long long i = 0; i < M; i++) cin >> E[i].first >> E[i].second;
	vector<long long> Ans(M);
	vector<long long> par(N, -1);
	Ans[M - 1] = N * (N - 1) / 2;
	for (long long i = M - 1; i >= 1; i--) {
		long long a = E[i].first, b = E[i].second;
		Ans[i - 1] = Ans[i];
		long long ra = root(a - 1, par);
		long long rb = root(b - 1, par);
		if (ra != rb) {
			Ans[i - 1] -= size(a - 1, par) * size(b - 1, par);
			par[rb] += par[ra];
			par[ra] = rb;
		}
	}
	for (long long a : Ans) cout << a << endl;
}
