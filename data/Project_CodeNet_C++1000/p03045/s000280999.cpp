#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#include <stack>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 1000000000000

using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

vector< vector<int> > G(100005);
bool visited[100005];

void dfs(int root) {
	stack<int> s;
	visited[root] = true;
	s.push(root);
	while(!s.empty()) {
		int cur = s.top();
		s.pop();
		for (const int child : G[cur]) {
			if (visited[child])
				continue;
			s.push(child);
			visited[child] = true;
		}
	}
}

int main () {
	int N, M;
    cin >> N >> M;
	int x, y, z;
	rep(i,M) {
		cin >> x >> y >> z;
		--x;
		--y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (visited[i])
			continue;
		dfs(i);
		++ans;
	} 
	cout << ans << endl;
    return 0;
}