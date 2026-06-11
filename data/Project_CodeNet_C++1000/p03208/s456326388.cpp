#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	int n, k;
	
	cin >> n >> k;
	vector<int> h(n);
	int max = INF;
	for (int i = 0; i < n; i++) {
		cin >> h.at(i);
	}
	sort(h.begin(), h.end());
	for (int i = 0; i < n - k+1; i++) {
		if (h.at(k-1 + i) - h.at(i) < max) {
			max = h.at(k + i-1) - h.at(i);
		}
	}
	cout << max << endl;
	return 0;
}