#include <bits/stdc++.h>

using namespace std;
 
int main() {
	const int INF = 1e9;
	int K;
	cin >> K;

	vector<int> d(K, INF);
	d[1] = 0;
	deque<int> que;
	que.push_front(1);
	while (!que.empty()) {
		int from = que.front(); 
		que.pop_front();

		int to1 = (from + 1) % K;
		int to10 = (from * 10) % K;

		if (d[to1] > d[from] + 1) {
			d[to1] = d[from] + 1;
			que.push_back(to1);
		}
		if (d[to10] > d[from]) {
			d[to10] = d[from];
			que.push_front(to10);
		}
	}

	int res = d[0] + 1;
	cout << res << endl;

	return 0;
}
