#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"

#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nya_n "(=^･ω･^=)"
typedef long long ll;
using namespace std;

int n, m, l, r, d;
vector<pair<int, int>> g[100000];
pair<int, bool>gp[100000];
bool flag;

int dfs(int x) {
	if (flag) return 0;
	lp(g[x].size()) {
		if (gp[g[x][i].first].second) {
			if (gp[x].first + g[x][i].second != gp[g[x][i].first].first) {
				flag = true;
				return 0;
			}
		}
		else {
			gp[g[x][i].first] = make_pair(gp[x].first + g[x][i].second, true);
			dfs(g[x][i].first);
		}
	}
	return 0;
}



int main() {
	cin >> n >> m;
	lp(m) {
		cin >> l >> r >> d;
		g[l - 1].push_back(make_pair(r - 1, d));
		g[r - 1].push_back(make_pair(l - 1, -d));
	}
	lp(n)
		gp[i].second = false;
	flag = false;
	lp(n) {
		if (!gp[i].second) {
			gp[i] = make_pair(0, true);
			dfs(i);
			if (flag) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}