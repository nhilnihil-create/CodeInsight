#include <vector>
#include <iostream>

#define ff first
#define ss second
using namespace std;
#define MOD 1000000007
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

long long n;
vector<vector<long long>> gr;

long long add(long long a, long long b) {
	a += b;
	if (a >= MOD) a %= MOD;
	return a;
}

void mult(long long &a, long long b) {
	a = ((a % MOD) * (b % MOD)) % MOD;
}

pair<long long, long long> dfs(long long curr, long long par) {
	pair<long long, long long> res = {1, 1};

	for (auto child : gr[curr]) {
		if (child != par) {
			pair<long long, long long> q = dfs(child, curr);
			mult(res.ff, q.ff + q.ss);
			mult(res.ss, q.ff);
		}
	}
	return res;
}

int main() {

	cin >> n;
	gr.resize(n + 1);
	for (long long i = 1; i <= n - 1; i++) {
		long long u, v; cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	pair<long long, long long> ans = dfs(1, 1);
	cout << add(ans.ff, ans.ss);

	return 0;
}