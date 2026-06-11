#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100000;

int main() {
	ll m, k;
	cin >> m >> k;

	if(k >= (1 << m)) {
		cout << -1 << endl;
		return 0;
	}

	if(k == 0) {
		for(int i = 0; i < (1 << m) - 1; i++) {
			cout << i << ' ' << i << ' ';
		}
		cout << (1 << m) - 1 << ' ' << (1 << m) - 1 << endl;
		return 0;
	}

	ll x = 0;
	for(int i = 0; i < (1 << m); i++) {
		if(i != k) {
			x ^= i;
		}
	}
	if(x != k) {
		cout << -1 << endl;
		return 0;
	}

	cout << k;
	for(int i = 0; i < (1 << m); i++) {
		if(i != k) {
			cout << ' ' << i;
		}
	}
	cout << ' ' << k;
	for(int i = (1 << m) - 1; i >= 0; i--) {
		if(i != k) {
			cout << ' ' << i;
		}
	}
	cout << endl;
}
