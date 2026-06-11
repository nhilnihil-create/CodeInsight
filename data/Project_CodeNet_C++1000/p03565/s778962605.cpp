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
	string s, t;
	cin >> s >> t;
	int ss = s.size(), ts = t.size();
	vector<int> pos;
	if (ss < ts) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	for (int i = 0; i <= ss - ts; ++i) {
		bool ok = true;
		rep(j, ts) {
			if (s[i + j] != t[j] && s[i + j] != '?') {
				ok = false;
				break;
			}
		}
		if (ok)	pos.push_back(i);
	}
	if (pos.size() == 0) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	for (int i = pos.back(); i < pos.back() + ts; ++i) {
		s[i] = t[i - pos.back()];
	}
	rep(i, ss) {
		if (s[i] == '?')	s[i] = 'a';
	}
	cout << s << endl;
	return 0;
}