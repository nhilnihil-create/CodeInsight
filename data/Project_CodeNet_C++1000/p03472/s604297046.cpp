#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
	int n, h;
	cin >> n >> h;
	int ans = 0;
	vector<P> p(n);
	int second_max = 0;
	rep(i, n) {
		cin >> p[i].second >> p[i].first;
		second_max = max(second_max, p[i].second);
	}
	sort(p.rbegin(), p.rend());
	int index = 0;
	while (second_max < p[index].first) {
		index++;
		if (index == n)	break;
	}
	int tmp_i = 0;
	while (0 < h && tmp_i < index) {
		h -= p[tmp_i].first;
		tmp_i++;
		ans++;
	}
	if (h <= 0) {
		cout << ans << endl;
		return 0;
	}
	ans += h / second_max;
	if (h % second_max != 0)	ans++;
	cout << ans << endl;
	return 0;
}