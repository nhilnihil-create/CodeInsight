#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int const MAX = 200005;
long long const INF = 100000000000000000;
struct edge
{
	int from; int to; long long value;
};

vector<edge> g[MAX];
long long pos[MAX];
int n, m;

bool possible(int s) {
	stack<int> S;
	S.push(s);
	pos[s] = 0;
	while (!S.empty()) {
		int now = S.top();
		S.pop();
		for (int i = 0; i < g[now].size(); i++) {
			int next = g[now][i].to;
			int dist = g[now][i].value;
			if (pos[next] == INF) {
				pos[next] = pos[now] + dist;
				S.push(next);
			}else{
				if (pos[next] - pos[now] != dist) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int f, t, v;
		cin >> f >> t >> v;
		g[f].push_back({ f,t,v });
		g[t].push_back({ t,f,-v });
	}
	for (int i = 1; i <= n; i++) {
		pos[i] = INF;
	}
	for (int i = 1; i <= n; i++) {
		if (pos[i] == INF) {
			if(!possible(i)){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}