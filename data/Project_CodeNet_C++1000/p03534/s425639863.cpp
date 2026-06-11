#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
using namespace std;

typedef long long ll;

string s;
int cnt[3], t[3];

int main() {
	cin >> s;
	for (int i = 0; i < (int)s.length(); ++i) ++cnt[s[i] - 'a'];
	int mi = cnt[0], ma = cnt[0];
	for (int i = 0; i < 3; ++i) {
		mi = min(mi, cnt[i]);
		ma = max(ma, cnt[i]);
	}
	if (ma - mi <= 1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}