#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	vector<int> v(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	cout << 10 * v[2] + v[1] + v[0] << endl;
}