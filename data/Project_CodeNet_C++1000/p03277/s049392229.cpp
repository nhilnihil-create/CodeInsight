#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define MOD 1000000007 
#define INF 1000000000000000000
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

const int N = 200 * 1000 + 5;
vector <int> tree(N);
int getsum(int id) {
	int res = 0;
	while(id > 0) {
		res += tree[id];
		id -= (id & -id);
	}
	return res;
}
void update(int id, int val) {
	while(id < N) {
		tree[id] += val;
		id += (id & -id);
	}
}
int main() {
	int n;
	cin >> n;
	vector <int> A(n);
	map <int, int> m, rm;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		m[A[i]];
	}
	int x = 0;
	for (auto g : m) {
		m[g.ff] = ++x;
		rm[x] = g.ff;
	}
	for (int i = 0; i < n; i++) {
		A[i] = m[A[i]];
	}
	auto check = [&](int mid) {
		vector <int> pre(n);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			pre[i] = (A[i] <= mid ? -1 : 1);
			if(i > 0)
				pre[i] += pre[i - 1];
			if(pre[i] < 0)
				ans++;
		}
		for (int i = 0; i < n; i++) {
			pre[i] += (n + 1);
		}
		for (int i = 0; i < n; i++) {
			ans += (i - getsum(pre[i]));
			update(pre[i], 1);
		}
		tree.assign(N - 1, 0);
		return ans;
	};
	int lo = 1, hi = n, ans = -1;
	ll total = 1LL * n * (n + 1) / 2;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if(check(mid) >= total / 2 + 1) {
			ans = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << rm[ans];
}
