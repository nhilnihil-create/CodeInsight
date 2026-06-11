#include <iostream>
#include <vector>

using namespace std;
void set(long long N, vector<long long>& par) {
	for (long long i = 0; i < N; i++) par[i] = -1;
}

long long root(long long x, vector<long long>& par) {
	if (par[x] < 0) return x;
	return par[x] = root(par[x], par);
}

void unite(long long x, long long y, vector<long long>& par) {
	long long rx = root(x, par);
	long long ry = root(y, par);
	if (rx == ry) return;
	par[ry] += par[rx];
	par[rx] = ry;
}
bool same(long long x, long long y, vector<long long>& par) {
	long long rx = root(x, par);
	long long ry = root(y, par);
	return rx == ry;
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
	vector<long long> par(N);
	set(N, par);
	Ans[M - 1] = N * (N - 1) / 2;
	for (long long i = M - 1; i >= 1; i--) {
		long long a = E[i].first, b = E[i].second;
		Ans[i - 1] = Ans[i];
		if (!same(a - 1, b - 1, par)) {
			Ans[i - 1] -= size(a - 1, par) * size(b - 1, par);
			unite(a - 1, b - 1, par);
		}
	}
	for (long long a : Ans) cout << a << endl;
}
