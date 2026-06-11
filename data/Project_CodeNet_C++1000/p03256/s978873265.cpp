#include <iostream>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>
#include <climits>
#include <map>
#include <queue>
#include <math.h>
#include <iomanip>

#define sqr(A) ((A) * (A))
#define F first
#define S second
#define MP make_pair
#define bsz  __builtin_popcount
#define all(A) A.begin(), A.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int PR = 727;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;

const int N = 2e5 + 20;
vector<int> G[N];
bool visited[N];
int n, m, A[N], B[N];
string s;
queue<int> q;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	s = '*' + s;
	for (int i = 0, v, u; i < m; i++) {
		cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
		if (s[v] == 'A')
			A[u]++;
		else
			B[u]++;
		if (s[u] == 'A')
			A[v]++;
		else
			B[v]++;
	}
	for (int v = 1; v <= n; v++)
		if (!A[v] || !B[v])
			visited[v] = 1, q.push(v);
	while (q.size()) {
		int v = q.front(); q.pop();
		for (int u : G[v]) {
			if (s[v] == 'A')
				A[u]--;
			else
				B[u]--;
			if ((!A[u] || !B[u]) && !visited[u])
				visited[u] = 1, q.push(u);
		}
	}
	for (int v = 1; v <= n; v++)
		if (!visited[v])
			return cout << "Yes" << endl, 0;
	cout << "No" << endl;
}





























