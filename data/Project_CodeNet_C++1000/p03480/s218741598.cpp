#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define DEC(i, a, b) for (int i = (int)a; i >= (int)b; i--)
#define f first
#define s second

int n, ans = 1e9;
string str;

int main() {
	cin >> str;
	n = str.length();
	ans = n;
	FOR(i, 0, n-2) {
		if (str[i] != str[i+1]) ans = min(ans, max(i+1, n-i-1));
	}
	cout << ans;
}
