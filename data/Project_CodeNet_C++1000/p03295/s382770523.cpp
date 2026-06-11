#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> v(M);
	for (int i = 0; i < M; i++) {
		cin >> v.at(i).first >> v.at(i).second;
	}
	sort(v.begin(), v.end(), cmp);

	int ans = 1;
	int x = v.at(0).second;
	for (int i = 1; i < M; i++) {
		if (v.at(i).first >= x) {
			ans++;
			x = v.at(i).second;
		}
	}

	cout << ans << endl;
}