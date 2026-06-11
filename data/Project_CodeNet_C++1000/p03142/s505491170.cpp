#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

const int SIZE = 100010;
 
vector<int> G[SIZE];
int deg[SIZE];
int ord[SIZE];
 
int main() {
	int n, m;
    cin >> n >> m;
	
    rep(i, n-1+m) {
        int a, b;
        cin >> a >> b;
		a--;  b--;
		deg[a]++;
		G[b].push_back(a);
    }
	
	queue<int> Q;

	rep(v, n) {
		if(deg[v] == 0) {
			Q.push(v);
		}
	}

	int sz = 0;
	while(!Q.empty()) {
		int v = Q.front();
        Q.pop();
		ord[v] = sz++;
		rep(i, G[v].size()) {
			int u = G[v][i];
			deg[u]--;
			if(deg[u] == 0) {
                Q.push(u);
            }
		}
	}

	rep(i, n) {
		int mn = SIZE;
        int pos = -1;
		rep(j, G[i].size()) {
			int u = G[i][j];
			if(mn > ord[u]) {
				mn = ord[u];
				pos = u;
			}
		}
		cout << pos + 1 << "\n";
	}

	return 0;
}