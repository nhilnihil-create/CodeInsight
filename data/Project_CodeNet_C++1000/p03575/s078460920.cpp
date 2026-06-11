#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;

const int nmax = 50;
int n, m;
int A[nmax], B[nmax];
bool graph[nmax][nmax];
bool visited[nmax];

void dfs(int v) {
	visited[v] = true;
	for (int v2=0; v2<n; v2++) {
		if (graph[v][v2]==false) continue;
		if (visited[v2]==true) continue;
		dfs(v2);
	}
}

int main() {
	cin >> n >> m;
	rep(i, m) {
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
		graph[A[i]][B[i]] = graph[B[i]][A[i]] = true;
	}
	int ans = 0;
	for (int i=0; i<m; i++) {
		graph[A[i]][B[i]] = graph[B[i]][A[i]] = false;
		rep(v, n) visited[v] = false;
		dfs(0);
		bool bridge = false;
		rep(v, n) {
			if (visited[v]==false) bridge = true;
		}
		if (bridge) ans++;
		graph[A[i]][B[i]] = graph[B[i]][A[i]] = true;
	}
	cout << ans << endl;
}