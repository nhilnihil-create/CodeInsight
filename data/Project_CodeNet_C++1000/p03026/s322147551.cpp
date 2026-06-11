#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

typedef struct {
	vector<int> edge;
	ll cost;
}node_t;
vector<node_t> node;

int main(void) {
	int N;
	cin >> N;

	node = vector<node_t>(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		node[a].edge.push_back(b);
		node[b].edge.push_back(a);
	}

	ll total = 0;
	priority_queue<ll> C;
	for (int i = 0; i < N; i++) {
		ll c;
		cin >> c;
		total += c;
		C.emplace(c);
	}

	queue<int> q;
	vector<bool> visit(N + 1);
	q.push(1);
	visit[1] = true;
	node[1].cost = C.top();
	C.pop();

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto to : node[x].edge) {
			if (visit[to]) continue;
			visit[to] = true;
			q.push(to);
			node[to].cost = C.top();
			C.pop();
		}
	}

	cout << total - node[1].cost << endl;
	for (int i = 1; i <= N; i++) {
		cout << node[i].cost << " ";
	}
	cout << endl;
}
