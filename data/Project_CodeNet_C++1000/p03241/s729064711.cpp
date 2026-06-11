#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
vector<int> divisor(int n)
{
	vector<int> ret;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n)	ret.push_back(n / i);
		}
	}
	return ret;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> vec;
	vec = divisor(m);
	sort(vec.begin(), vec.end());
	int s = vec.size();
	int ans = 1;
	rep(i, s) {
		if (ll(vec[i]) * ll(n) <= ll(m)) ans = vec[i];
	}
	cout << ans << endl;
	return 0;
}