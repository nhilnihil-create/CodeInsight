#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	vector<int> v(3);
	for (int i = 0; i < 3; i++) cin >> v.at(i);
	sort(v.begin(), v.end());

	int ans = abs(v.at(0) - v.at(1)) + abs(v.at(1) - v.at(2));

	cout << ans << endl;
}