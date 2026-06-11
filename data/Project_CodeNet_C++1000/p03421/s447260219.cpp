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
#define INF 1000000000000000000
#define MOD 998244353
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	if(!(n >= b + a - 1 && n <= a * b)) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		vector <int> t;
		while(n - i >= a - 1 && cnt < b) {
			t.push_back(i);
			i++;
			cnt++;
		}
		i--;
		reverse(all(t));
		for (auto g : t)
			cout << g << " ";
		a--;
	}
}
