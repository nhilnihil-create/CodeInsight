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
	int N;
	cin >> N;
	vector< pair<cat, int> > D(N);
	for(int i = 0; i < N; i++) {
		cin >> D[i].ff;
		D[i].ss = i;
	}
	sort(begin(D), end(D));
	map<cat, int> M;
	for(int i = 0; i < N; i++) M[D[i].ff] = i;
	vector<int> sz(N, 1);
	vector< pair<int, int> > E;
	for(int i = N-1; i > 0; i--) {
		if(2*sz[i] >= N) {
			cout << "-1\n";
			return 0;
		}
		cat D_up = D[i].ff + sz[i] - (N-sz[i]);
		auto it = M.find(D_up);
		if(it == M.end()) {
			cout << "-1\n";
			return 0;
		}
		sz[it->ss] += sz[i];
		E.push_back({D[i].ss, D[it->ss].ss});
	}
	if(sz[0] != N || (int)E.size() != N-1) {
		cout << "-1\n";
		return 0;
	}
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		G[E[i].ff].push_back(E[i].ss);
		G[E[i].ss].push_back(E[i].ff);
	}
	vector<int> dep(N, -1);
	dep[D[0].ss] = 0;
	queue<int> q;
	q.push(D[0].ss);
	while(!q.empty()) {
		ALL_THE(G[q.front()], it) if(dep[*it] == -1) {
			dep[*it] = dep[q.front()] + 1;
			q.push(*it);
		}
		q.pop();
	}
	cat depsum = 0;
	for(int i = 0; i < N; i++) {
		if(dep[i] == -1) {
			cout << "-1\n";
			return 0;
		}
		depsum += dep[i];
	}
	if(depsum != D[0].ff) {
		cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < (int)E.size(); i++) cout << E[i].ff+1 << " " << E[i].ss+1 << "\n";
	return 0;
}

// look at my code
// my code is amazing
