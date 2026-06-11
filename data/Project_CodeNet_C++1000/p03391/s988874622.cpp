//何も分からないので実験した。最初A≠Bのときを考える。
//・最後に正の値が残るとしたら、それは1箇所。A_i > B_iだった所になるようだ。
//・A_i > B_iを満たすiの元, B_iの最小値を求めると、それが最終的な数列A, Bの和と一致するようだ。
//証明はしていない。
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n;
int a, b;

signed main() {
	int i;
	int s = 0, minB = 1e+10;
	
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		s += a + b;
		if (a > b) minB = min(minB, b);
	}
	if (minB == 1e+10) cout << 0 << endl;
	else cout << (s - 2 * minB) / 2 << endl;
	return 0;
}