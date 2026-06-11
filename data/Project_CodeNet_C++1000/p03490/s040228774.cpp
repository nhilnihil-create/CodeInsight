#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 998244353
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

const int N = 8000;
unordered_map <int, bool> dp[N];
vector <int> v[2];
bool func(int i, int csum, int dir, int dest) {
	if(i == (int) v[dir].size()) {
		return (csum == dest);
	}
	if(dp[i].find(csum) != dp[i].end())
		return dp[i][csum];
	bool val = (func(i + 1, csum + v[dir][i], dir, dest) 
				| func(i + 1, csum - v[dir][i], dir, dest));
	return dp[i][csum] = val;
}
int main() {
	string s;
	cin >> s;
	int n = (int) s.size();
	int dx, dy;
	cin >> dx >> dy;
	int pos = 0;
	while(pos < n && s[pos] != 'T')
		pos++;
	int cx = pos;
	int p = 1, c = 0;
	for (int i = pos + 1; i < n; i++) {
		if(s[i] == 'F') {
			c++;
		}
		else {
			v[p].push_back(c);
			c = 0;
			p ^= 1;
		}
	}
	if(c > 0) {
		v[p].push_back(c);
	}
	bool xp = func(0, cx, 0, dx);
	for (int i = 0; i < N; i++)
		dp[i].clear();
	bool yp = func(0, 0, 1, dy);
	if(xp & yp) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}
