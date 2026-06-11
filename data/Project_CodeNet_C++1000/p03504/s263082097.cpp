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
#include <bitset>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


int main() {
	int N, C; cin >> N >> C;
	vector<vector<int>> s(32, vector<int>(100005));
	for (int i = 0; i < N; i++) {
		int a, b, c; cin >> a >> b >> c;
		s[c][a]++;
		s[c][b + 1]--;
	}
	for (int c = 0; c <= C; c++) {
		for (int i = 0; i < 100002; i++) s[c][i + 1] += s[c][i];
	}
	int ans = 0;
	for (int i = 0; i < 100002; i++) {
		int cnt = 0;
		for (int j = 0; j <= C; j++) {
			cnt += s[j][i] >= 1;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
