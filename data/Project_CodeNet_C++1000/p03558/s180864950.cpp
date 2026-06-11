#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <tuple>
#include <functional>
#include <bitset>
#define INF 1000000009
#define LINF 1000000000000000009
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmax(T &a, const T&b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T&b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

int main(){
	int k;
	cin >> k;
	vector<vector<P>> graph(k, vector<P>());
	for (int i = 0; i < k; i++) {
		graph[i].push_back(P((i + 1) % k, 1));
		graph[i].push_back(P((10 * i) % k, 0));
	}
	vector<int> ans(k);
	for (int i = 0; i < k; i++) ans[i] = INF;
	ans[1] = 1;
	priority_queue<P, vector<P>, greater<P>> que;
	que.push(P(1, 1));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (ans[v] < p.first) continue;
		for (auto i : graph[v]) {
			if (ans[i.first] > ans[v] + i.second) {
				ans[i.first] = ans[v] + i.second;
				que.push(P(ans[i.first], i.first));
			}
		}
	}
	cout << ans[0] << endl;
}