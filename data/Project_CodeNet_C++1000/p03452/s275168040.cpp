#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long llu;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
const ll MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<int, vector<int>, greater<int> > pq;
vector<pii> v[100000];

int dist[100000];
void go(int o, int val) {
	if (dist[o] != -1) {
		if (dist[o] != val) {
			printf("No\n");
			exit(0);
		}
		else return;
	}
	else dist[o] = val;

	for (int i = 0; i < sz(v[o]); i++)
		go(v[o][i].second, val + v[o][i].first);
}

int main() {
	memset(dist, -1, sizeof(dist));
	int n, m;
	scanf("%d %d", &n, &m);

	int a, b, c;
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		v[a].push_back({ c, b });
		v[b].push_back({ -c, a });
	}

	for (int i = 0; i < n; i++)
		if(dist[i] == -1) go(i, 1000000000);

	printf("Yes\n");
}