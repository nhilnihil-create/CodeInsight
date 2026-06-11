#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

int K;
int dis[100000];

typedef pair<int, int> P;

void djk() {
	priority_queue<P, vector<P>, greater<P>> pq;
	for (int i = 0; i < K; i++)dis[i] = 1145141919;
	
	dis[1] = 1;
	pq.push(P(1, 1));
	while (pq.size()) {
		P now = pq.top(); pq.pop();
		int total = now.first, pos = now.second;
		if (dis[pos] < total)continue;

		//10倍する
		if (dis[(pos * 10) % K] > total) {
			int nxt = (pos * 10) % K;
			dis[nxt] = total;
			pq.push(P(total, nxt));
		}

		//+1する
		if (dis[(pos + 1) % K] > total + 1) {
			int nxt = (pos + 1) % K;
			dis[nxt] = total + 1;
			pq.push(P(total + 1, nxt));
		}
	}
}

int main() {
	cin >> K;
	djk();
	cout << dis[0] << endl;
	return 0;
}