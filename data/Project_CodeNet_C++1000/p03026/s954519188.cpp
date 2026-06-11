#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define INIT -1

int main() {
	int n;
	cin >> n;
	vector<vector<int> > graph(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int c[100000];
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(c, c + n);
	long long int m = accumulate(c, c + n - 1, 0);
	vector<int> d(n, -1);
	queue<int> qu;
	qu.push(0);
	for (int i = n - 1; i >= 0; i--) {
		int now = qu.front();
		// cout << now << endl;
		d[now] = c[i];
		qu.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (d[next] >= 0) continue;
			qu.push(next);
		}
	}
	cout << m << endl;
	for (int i = 0; i < n; i++) {
		cout << d[i] << " ";
		if (i == n - 1)
			cout << endl;
		else
			cout << " ";
	}
}