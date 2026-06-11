#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	string S;
	cin >> N >> M >> S;
	vector< vector<int> > G(2*N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		if(S[u] == S[v]) {
			G[2*u].push_back(2*v+1);
			G[2*v].push_back(2*u+1);
		}
		else {
			G[2*u+1].push_back(2*v);
			G[2*v+1].push_back(2*u);
		}
	}
	vector<int> deg(2*N, 0);
	for(int i = 0; i < 2*N; i++) ALL_THE(G[i], it) deg[*it]++;
	queue<int> q;
	for(int i = 0; i < 2*N; i++) if(deg[i] == 0) q.push(i);
	int proc = 0;
	while(!q.empty()) {
		proc++;
		ALL_THE(G[q.front()], it) {
			deg[*it]--;
			if(deg[*it] == 0) q.push(*it);
		}
		q.pop();
	}
	cout << ((proc < 2*N) ? "Yes\n" : "No\n");
	return 0;
}

// look at my code
// my code is amazing
