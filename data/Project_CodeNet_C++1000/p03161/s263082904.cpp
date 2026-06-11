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

int n, k;
vector<int> h;
vector<int> c;

int cost_i2j(int i, int j) {
	return abs(h[j] - h[i]);
}

int main(void) {
	cin >> n >> k;
	h.resize(n + 1);
	c = vector<int>(n + 1, 0);
	for (int i = 1; i < n + 1; i++)
		cin >> h[i];

	for (int i = 2; i < n + 1; i++) {
		int tmp = c[i-1] + cost_i2j(i-1, i);
		for (int j = 2; j < min(i, k+1); j++)
			tmp = min(tmp, c[i - j] + cost_i2j(i - j, i));
		c[i] = tmp;
	}
	cout << c[n] << endl;
	return 0;
}