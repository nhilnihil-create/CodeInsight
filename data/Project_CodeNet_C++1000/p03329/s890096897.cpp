#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> c;
	for (int i = 6; i <= N; i *= 6) c.push_back(i);
	for (int i = 9; i <= N; i *= 9) c.push_back(i);
	sort(c.begin(), c.end());

	vector<int> dp(N + 1);
	for (int i = 0; i <= N; i++) {
		dp.at(i) = i;
		for (int j = 0; j < c.size(); j++) {
			if (i < c.at(j)) break;
			dp.at(i) = min(dp.at(i), dp.at(i - c.at(j)) + 1);
		}
	}

	cout << dp.at(N) << endl;
}