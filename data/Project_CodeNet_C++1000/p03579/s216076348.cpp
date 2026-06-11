#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>


using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 1999999999999999999
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007

bool two = true;
ll n, m, s[110000], w = 0, b = 0;
vector<vector<ll>> list(110000);

void dfs(ll a) {
	REP(i, list[a].size()) {
		if (s[list[a][i]] == s[a]) two = false;
		else if (s[list[a][i]] == 0) {
			if (s[a] == 1) {
				s[list[a][i]] = 2;
				b++;
			}
			else {
				s[list[a][i]] = 1;
				w++;
			}
			dfs(list[a][i]);
		}
	}
}

int main() {
	cin >> n >> m;
	REP(i, m) {
		ll a, b;
		cin >> a >> b;
		list[a].push_back(b);
		list[b].push_back(a);
	}
	s[1] = 1;
	w++;
	dfs(1);
	cout << (two ? w * b - m : n * (n - 1) / 2 - m) << endl;
}