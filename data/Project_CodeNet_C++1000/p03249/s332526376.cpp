#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	if (N == 2) {
		cout << -1 << endl;
		return 0;
	}
	vector<long long int>v(N);
	map<long long int, int>m;
	map<long long int, int>used;
	L = LLONG_MAX;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		m[v[i]] = i + 1;
		L = min(L, v[i]);
	}
	vector<pair<int, int>>ans;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (auto i : v) {
		if (i == L)break;
	//	cout << i << endl;
		long long int dif = N - 2 - used[i] * 2;
		long long int box = i;
		if (m.find(box - dif) == m.end()) {
			cout << "-1\n";
			return 0;
		}
		ans.push_back({ m[box],m[box - dif] });
	//	cout << box << " " << box - dif << endl;
		used[box - dif] += used[box] + 1;
		box -= dif;
		dif -= 2;
	}
	vector<vector<int>>edge(N + 1);
	for (auto i : ans) {
		edge[i.first].push_back(i.second);
		edge[i.second].push_back(i.first);
	}
	vector<int>dis(N + 1, MOD);
	dis[m[L]] = 0;
	queue<int>Q;
	Q.push(m[L]);
	while (!Q.empty()) {
		int cn = Q.front(); 
		Q.pop();
		for (auto i : edge[cn]) {
			if (dis[i] > dis[cn] + 1) {
				dis[i] = dis[cn] + 1;
				Q.push(i);
			}
		}
	}
	long long int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += dis[i];
	}
	if (sum != L) {
		cout << -1 << endl;
		return 0;
	}
	for (auto i : ans) {
		cout << i.first << " " << i.second << endl;
	}
	return 0;
} 
