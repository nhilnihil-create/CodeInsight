#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;
typedef long long signed int ll;

constexpr int inf = INT32_MAX / 2;

int n, t[100],s[101], v[100],vmax[40001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		t[i] *= 2;
	}
	s[0] = 0;
	for (int i = 0; i < n; i++) s[i + 1] = s[i] + t[i];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i] *= 2;
	}
	for (int i = 0; i <= s[n]; i++) vmax[i] = min(i,s[n] - i);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s[i]; j++) {
			vmax[j] = min(vmax[j], v[i] + (s[i] - j));
		}
		for (int j = s[i]; j < s[i+1]; j++) {
			vmax[j] = min(vmax[j], v[i]);
		}
		for (int j = s[i+1]; j <= s[n]; j++) {
			vmax[j] = min(vmax[j], v[i] + (j - s[i+1]));
		}
	}
	int res = 0;
	for (int i = 0; i <= s[n]; i++) {
		res += vmax[i];
	}
	cout << setprecision(20) <<((double)res)/((double)4) << endl;
}