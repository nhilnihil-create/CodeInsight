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
//first
using namespace std;
using ll = long long;

typedef struct {
	int par;
	int hei = 1;
	ll mem = 1;
}node_t;
vector<node_t> node;

int root(int a) {
	if (node[a].par == 0) return a;
	else return root(node[a].par);
}

void unite(int art, int brt) {
	int up, low;
	if (node[art].hei >= node[brt].hei) up = art, low = brt;
	else up = brt, low = art;
	node[low].par = up;
	node[up].hei = max(node[up].hei, node[low].hei + 1);
	node[up].mem += node[low].mem;
}
int main(void) {
	ll N, M;
	cin >> N >> M;

	vector<pair<int, int>> bri(M);
	for (int i = 0; i < M; i++) {
		cin >> bri[i].first >> bri[i].second;
	}

	node = vector<node_t>(N + 1);
	vector<ll> ans(M);
	ans[M - 1] = N * (N - 1) / 2;
	for (int i = M - 1; i >= 1; i--) {
		ans[i - 1] = ans[i];
		int a = bri[i].first, b = bri[i].second;
		int art = root(a), brt = root(b);
		if (art == brt) continue;
		ans[i - 1] -= (node[art].mem * node[brt].mem);
		unite(art, brt);
	}

	for (int i = 0; i < M; i++) {
		cout << ans[i] << endl;
	}

}
