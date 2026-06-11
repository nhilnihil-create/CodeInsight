#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define for1(i, n) for(int i = 1; i <= (n);i++)
using namespace std;
int ac = 0, qc1 = 0, qc2 = 0, cc = 0, k = 1;
int ans = 0, ans0 = 0, ans1 = 0, ans2 = 0, ans3 = 0;
string s;
signed main() {
	cin >> s;
	for (char ch : s) {
		if (ch == '?')qc2++;
		if (ch == 'C')cc++;
	}
	for (char ch : s) {
		if (ch == '?')qc2--;
		if (ch == 'C')cc--;
		if (ch == '?') {
			ans1 += ac * cc;
			ans2 += qc1 * cc + ac * qc2;
			ans3 += qc1 * qc2;
			ans1 %= mod; ans2 %= mod; ans3 %= mod;
		}
		if (ch == 'B') {
			ans0 += ac * cc;
			ans1 += qc1 * cc + ac * qc2;
			ans2 += qc1 * qc2;
			ans1 %= mod; ans2 %= mod; ans0 %= mod;
		}
		if (ch == '?')qc1++;
		if (ch == 'A')ac++;
	}
	for1(i, qc1 - 3) { k *= 3; k %= mod; }
	if (qc1 >= 3) {
		ans += k * ans3; ans %= mod;
		k *= 3; k %= mod;
	}
	if (qc1 >= 2) {
		ans += k * ans2; ans %= mod;
		k *= 3; k %= mod;
	}
	if (qc1 >= 1) {
		ans += k * ans1; ans %= mod;
		k *= 3; k %= mod;
	}
	if (qc1 >= 0) {
		ans += k * ans0; ans %= mod;
		k *= 3; k %= mod;
	}
	cout << ans << endl;
}