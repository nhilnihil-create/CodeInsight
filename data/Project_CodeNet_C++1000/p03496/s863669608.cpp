#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#define BUF 50
#define INF 1<<30
using namespace std;
ll MOD = 1e9 + 7;
ll A, B, C, D, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S;
ll ans = 0;
int main() {
	cin >> N;
	vector<int>a(N);
	vector<pair<int, int>>res;
	for (int i = 0; i < N; i++)cin >> a[i];
	auto mxit = max_element(a.begin(), a.end());
	auto mnit = min_element(a.begin(), a.end());
	if (*mnit < 0 && *mxit < abs(*mnit)) {
		for (int i = 1; i <= N; i++)res.push_back({ distance(a.begin(),mnit) + 1, i });
		for (int i = N; i > 1; i--)res.push_back({ i, i - 1 });
	}
	else {
		for (int i = 1; i <= N; i++)res.push_back({ distance(a.begin(),mxit) + 1,i });
		for (int i = 1; i < N; i++)res.push_back({ i,i + 1 });
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)cout << res[i].first << " " << res[i].second << endl;
}