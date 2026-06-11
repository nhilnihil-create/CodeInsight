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
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	string s;
	cin >> s;
	if (s.size() == 1) {
		cout << 0 << endl;
		return 0;
	}
	int ss = s.size();
	vector<pair<char, int>> ext;
	rep(i, ss) {
		if (s[i] != 'x')	ext.emplace_back(s[i], i);
	}
	if (ext.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	string b = "", e = "";
	rep(i, ext.size() / 2) {
		b += ext[i].first;
		e += ext[ext.size() - 1 - i].first;
	}
	if (b != e) {
		cout << -1 << endl;
		return 0;
	}
	int left, right;
	if (ext.size() % 2 == 1) {
		left = right = ext[ext.size() / 2].second;
	}
	else {
		left = ext[ext.size() / 2].second;
		right = ext[ext.size() / 2 - 1].second;
	}
	vector<int> bn(1, 0), en(1, 0);
	rep(i, left) {
		if (s[i] != 'x')	bn.push_back(0);
		else bn.back()++;
	}
	for (int i = ss - 1; i > right; --i) {
		if (s[i] != 'x')	en.push_back(0);
		else en.back()++;
	}
	int ans = 0;
	rep(i, bn.size()) {
		ans += abs(bn[i] - en[i]);
	}
	cout << ans << endl;
	return 0;
}