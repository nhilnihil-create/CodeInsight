#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>	// upper_bound(A, A+N, num):>, lower_bound(A, A+N, num):>=
#include <functional>
#include <string>
#include <sstream>
#include <complex>
#include <vector>	// V[i],  push_back(x), pop_back(), insert(index, x), erase(index), sort(v.begin(), v.end(), greater<int>())
#include <list>		// push_front(x), push_back(x), pop_front(), pop_back(), insert(index, x)
#include <queue>	// push(x), front(), pop()
#include <deque>
#include <stack>	// push(x), top(), pop()
#include <map>		// M[key],  insert(key, val), erase(key), find(key), 
#include <set>		// insert(key), erase(key), find(key)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define pi 3.141592653589793)
#define mod 1000000007
#define INF 100000000000000000LL

vector<P> vec[100005];
ll dp[100005];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int l, r, d;
		cin >> l >> r >> d;
		l--, r--;
		vec[l].push_back(P(r, d));
		vec[r].push_back(P(l, -d));
	}
	for (int i = 0; i < n; i++) dp[i] = INF;
	for (int i = 0; i < n; i++) {
		if (dp[i] == INF) {
			queue<int> que;
			que.push(i);
			dp[i] = 0;
			while (!que.empty()) {
				int v = que.front(); que.pop();
				for (int j = 0; j < vec[v].size(); j++) {
					P p = vec[v][j];
					int to = p.first, c = p.second;
					if (dp[to] == INF) {
						dp[to] = dp[v] + (ll)c;
						que.push(to);
					}
					else if (dp[to] != dp[v] + (ll)c) {
						cout << "No" << endl;
						return ;
					}
				}
			}
		}
	}
	cout << "Yes" << endl;
	return;
}

int main() {
	solve();
	return 0;
}