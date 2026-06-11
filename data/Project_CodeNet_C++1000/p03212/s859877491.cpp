#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	vector<ll>a;
	pq.push(3);
	pq.push(5);
	pq.push(7);
	while (pq.top() <= n) {
		a.push_back(pq.top());
		pq.push(pq.top() * 10 + 3);
		pq.push(pq.top() * 10 + 5);
		pq.push(pq.top() * 10 + 7);
		pq.pop();
	}
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		int x = a.at(i);
		if (x <= 332)continue;
		string y = to_string(x);
		sort(y.begin(), y.end());
		int k = 1;
		for (int j = 0; j < y.length(); j++) {
			if (k == 1 && y.at(j) == '3')k *= 2;
			if (k == 2 && y.at(j) == '5')k *= 2;
			if (k == 4 && y.at(j) == '7')k *= 2;
		}
		if (k == 8)ans++;
	}
	cout << ans << endl;
}