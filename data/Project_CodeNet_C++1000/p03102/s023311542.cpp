#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;



int main() {
	int n, m, c;
	cin >> n >> m >> c;
	vector<int>b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int s = c;
		for (int j = 0; j < m; j++) {
			s += a[i][j] * b[j];
		}

		if (s > 0) {
			cnt++;
		}
	}

	cout << cnt << endl;
}
