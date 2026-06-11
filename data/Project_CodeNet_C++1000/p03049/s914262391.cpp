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
	int n = 0;
	cin >> n;
	ll ans = 0;
	ll a_count, b_count, both_count;
	a_count = b_count = both_count = 0;
	string s;
	int pos = 0;
	rep(i, n) {
		cin >> s;
		pos = 0;
		while (1) {
			pos = s.find("AB", pos);
			if (pos != string::npos) {
				ans++;
				pos += 2;
			}
			else break;
		}
		if (s.back() == 'A' && s[0] == 'B')	both_count++;
		else if (s.back() == 'A')	a_count++;
		else if (s[0] == 'B')	b_count++;
	}
	ans += min(a_count, b_count) + both_count;
	if (a_count == 0 && b_count == 0 && both_count != 0)	ans--;
	cout << ans << endl;
	return 0;
}