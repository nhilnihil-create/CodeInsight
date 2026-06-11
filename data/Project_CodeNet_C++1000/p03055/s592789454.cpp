#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

vector<vector<int>> edge;
pair<int,int> bfs(int a,int N) {
	int id = 0, md = 0;
	queue<int> qu;
	qu.push(a);
	vector<bool> vi(N + 1);
	vi[a] = true;
	vector<int> dis(N + 1);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		//cout << "x=" << x << endl;
		for (auto to : edge[x]) {
			if (vi[to])continue;
			vi[to] = true;
			dis[to] = dis[x] + 1;
			qu.push(to);
			if (md < dis[to]) {
				md = dis[to];
				id = to;
			}
		}

	}

	return make_pair(id, md);
}

int main() {
	int N; cin >> N;
	edge=vector<vector<int>>(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int id = bfs(1, N).first;
	pair<int,int> L = bfs(id, N);
	//cout << "id=" << id << " L=" << L.second <<"to="<< L.first<<endl;
	if ((L.second + 1) % 3 == 2) cout << "Second" << endl;
	else cout << "First" << endl;
}


