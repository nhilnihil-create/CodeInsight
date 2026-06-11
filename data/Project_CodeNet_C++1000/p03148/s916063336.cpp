#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<ii> a(n);
	vector<int> x(n);	
	for(int i = 0; i < n; ++i)
		cin >> a[i].second >> a[i].first;	
	sort(a.rbegin(), a.rend());
	vector<bool> used(n + 1, false);
	x[0] = 1;
	used[a[0].second] = true;
	for(int i = 1; i < n; ++i) {
		x[i] = x[i - 1];
		if(!used[a[i].second]) {
			++x[i];
			used[a[i].second] = true;
		}
	}
	fill(used.begin(), used.end(), false);
	priority_queue<int, vector<int>, greater<int>> pq;
	long long tot = 0, X = 0;
	for(int i = 0; i < k; ++i) {
		if(used[a[i].second]) pq.push(a[i].first);
		used[a[i].second] = true;
		tot += a[i].first;
		X = x[i];
	}
	long long r = tot;
	tot += X * X;
	for(int i = k; i < n; ++i) {
		if(pq.empty()) break;
		else if(!used[a[i].second]) {
			++X;
			r += a[i].first - pq.top();
			tot = max(tot, r + X * X);
			pq.pop();
			used[a[i].second] = true;
		}
	}
	cout << tot << '\n';
	return 0;
}