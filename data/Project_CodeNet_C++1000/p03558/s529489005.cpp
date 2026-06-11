#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int K;
	cin >> K;

	priority_queue<P, vector<P>, greater<P>> que;
	vector<int> min_cost(K, -1);
	for(int i=1;i<10;i++) {
		que.emplace(i, i % K);
		min_cost[i % K] = i;
	}

	while(!que.empty()) {
		auto p = que.top();
		que.pop();
		int cost = p.first;
		int m = p.second;
		if (min_cost[m] < cost) continue;

		if(m == 0) {
			cout << cost << endl;
			return 0;
		}
		{
			int next_m = m;
			while (true) {
				next_m = (m * 10) % K;
				if (min_cost[next_m] == -1 || min_cost[next_m] > cost) {
					min_cost[next_m] = cost;
					que.emplace(cost, next_m);
				} else {
					break;
				}
			}
		}
		for(int i=1;i<10;i++) {
			int next_cost = cost + i;
			int next_m = (m * 10 + i) % K;
			if (min_cost[next_m] == -1 || min_cost[next_m] > next_cost) {
				min_cost[next_m] = next_cost;
				que.emplace(next_cost, next_m);
			}
		}
	}

	return 0;
}
