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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> cnt(26);
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']--;
		ll ansi = 1;
		for (int j = 0; j < 26; j++) {
			if (s[i] - 'a' != j) {
				ansi = (ansi * (cnt[j] + 1)) % MOD;
			}
		}
		ans = (ans + ansi) % MOD;
	}
	cout << ans;
}
