#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// AGC034-B, 1100, 
	string s; cin >> s;
	int n = s.size();
	int i = 0;
	ll ans = 0;
	int anum = 0;
	bool streak = false;
	while (i < n) {
		if (!streak) {
			if (s.find("A", i) == i) {
				streak = true;
				anum = 1;
			}
			i++;
			continue;
		}
		if (s.find("A", i) == i) {
			anum++;
			i++;
		}
		else if (s.find("BC", i) == i) {
			ans += ll(anum);
			i += 2;
		}
		else {
			streak = false;
			anum = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
