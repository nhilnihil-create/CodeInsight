#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<deque>
#include<numeric>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<string>

using namespace std;
using ll = long long int;
constexpr int INF = 1 << 29;
constexpr ll MOD = ll(1e9 + 7);

int n;
vector<int> h;
vector<int> c;

int cost_i2j(int i, int j) {
	return abs(h[j] - h[i]);
}

int main(void) {
	cin >> n;
	h.resize(n + 1);
	c = vector<int>(n + 1, 0);
	for (int i = 1; i < n + 1; i++)
		cin >> h[i];
	c[2] = cost_i2j(1, 2);
	for (int i = 3; i < n + 1; i++) {
		c[i] = min(c[i - 1] + cost_i2j(i-1, i), c[i - 2] + cost_i2j(i - 2, i));
	}
	cout << c[n] << endl;
	return 0;
}