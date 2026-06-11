#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define EPS (1e-15)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define bet(x, a, b) (a) <= (x) && (x) < (b)
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	string s;
	int len, ans = 0, non_x = 0;
	vector<int> vec;

	cin >> s;
	s = 'a' + s + 'a';
	len = s.length();

	rep(i, len) {
		if (s[i] != 'x') {
			non_x++;
			vec.push_back(i);
		}
	}

	int pre = 0;
	int pos = non_x - 1;

	while (pre <= pos) {
		if (s[vec[pre]] != s[vec[pos]]) {
			cout << -1 << endl;
			return 0;
		}

		if (pre != 0) {
			ans += abs((vec[pre] - vec[pre - 1]) - (vec[pos + 1] - vec[pos]));
		}

		pre++;
		pos--;
	}

	cout << ans << endl;

	return 0;
}
