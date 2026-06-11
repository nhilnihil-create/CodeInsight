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
	int n;
	cin >> n;
	vector <ll> A(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
	}
	ll ans = INF;
	int lo, hi, p;
	ll sum;
	auto diff = [&] (int x, ll c) {
		return abs((A[x] - c) - (sum - (A[x] - c)));
	};
	for (int i = 2; i <= n - 2; i++) {
		ll mn = INF, mx = 0;
		auto update = [&] (ll x) {
			mn = min(mn, x);
			mx = max(mx, x);
		};
		// part from 1...i
		lo = 1, hi = i - 1;
		sum = A[i];
		p = -1;
		while(lo <= hi) {
			int mid = (lo + hi) / 2;
			if(diff(mid, 0) <= diff(mid + 1, 0)) {
				p = mid;
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		update(A[p]);
		update(A[i] - A[p]);
		// part from i + 1 .... n
		lo = i + 1, hi = n - 1;
		sum = A[n] - A[i];
		p = -1;
		while(lo <= hi) {
			int mid = (lo + hi) / 2;
			if(diff(mid, A[i]) <= diff(mid + 1, A[i])) {
				p = mid;
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		update(A[p] - A[i]);
		update(sum - (A[p] - A[i]));
		ans = min(ans, mx - mn);
	}
	cout << ans;
}
