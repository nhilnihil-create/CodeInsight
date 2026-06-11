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
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> A(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		sum += A[i];
	}
	if (sum == k) {
		cout << n;
	}
	else if (sum < k) {
		cout << n - 1;
	}
	else {
		sort(all(A));
		ll cur = 0;
		for (int i = 0; i < n; i++) {
			cur += A[i];
			if (cur > k) {
				cout << i;
				return 0;
			}
		}
	}
}
