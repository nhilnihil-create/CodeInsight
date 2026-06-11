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


int main() {
	int l;
	cin >> l;
	l -= 1;
	int n = 20;
	vector <pair<int, pair<int, int>>> v;
	for (int i = 20; i >= 0; i--) {
		if((1 << i) - 1 <= l) {
			n = i + 1;
			break;
		}
	}
	for (int i = 1; i < n; i++) {
		v.push_back({i, {i + 1, 1 << (n - i - 1)}});
		v.push_back({i, {i + 1, 0}});
	}
	if(l > (1 << (n - 1)) - 1) {
		for (int i = 0; i <= 20; i++) {
			if(l & (1 << i)) {
				int mask = (l & (((1 << 20) - 1) ^ ((1 << (i + 1)) - 1)));
				if(mask != 0)
					v.push_back({1, {n - i, mask}});
			}
		}
		v.push_back({1, {n, l}});
	}
	
	cout << n << " " << (int) v.size() << "\n";
	for (auto g : v) {
		cout << g.ff << " " << g.ss.ff << " " << g.ss.ss << "\n";
	}
}
