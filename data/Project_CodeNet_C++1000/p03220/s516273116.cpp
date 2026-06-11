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
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;

int main(){
	int n;
	float a, t;
	float mini = INF;
	int ans = 0;
	cin >> n >> t >> a;
	vector<float> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h.at(i);
		h.at(i) = t - 0.006 * h.at(i);
		if (abs(a - h.at(i)) < mini) {
			mini = abs(a - h.at(i));
			ans = i;
		}
	}
	cout << ans+1 << endl;
	return 0;
}