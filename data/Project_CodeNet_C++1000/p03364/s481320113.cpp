#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
	int n, i, j, a, b, ans;
	string s[303];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		cin >> s[i];
	}

	ans = 0;

	for (a = 0; a < n; a++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (s[i][j] != s[(j + a) % n][(i - a + n) % n]) {
					break;
				}
			}
			if (j < n) {
				break;
			}
		}
		if (i == n) {
			ans += n - a;
		}
	}

	for (b = 1; b < n; b++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (s[i][j] != s[(j - b + n) % n][(i + b) % n]) {
					break;
				}
			}
			if (j < n) {
				break;
			}
		}
		if (i == n) {
			ans += n - b;
		}
	}

	printf("%d\n", ans);

	return 0;
}