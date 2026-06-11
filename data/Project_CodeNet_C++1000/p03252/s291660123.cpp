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
using p = pair<int, int>;
int main()
{
	string s, t;
	cin >> s >> t;
	int n = s.size();
	vector<int> snum(n), tnum(n);
	map<char, int> smp, tmp;
	int sc = 0, tc = 0;
	rep(i, n) {
		if (smp[s[i]] == 0) {
			smp[s[i]] = sc;
			snum[i] = sc;
			sc++;
		}
		else {
			snum[i] = smp[s[i]];
		}
		if (tmp[t[i]] == 0) {
			tmp[t[i]] = tc;
			tnum[i] = tc;
			tc++;
		}
		else {
			tnum[i] = tmp[t[i]];
		}
	}
	rep(i, n) {
		if (snum[i] != tnum[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
  	return 0;
}