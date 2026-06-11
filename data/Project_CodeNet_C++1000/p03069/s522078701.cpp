#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	string S;
	cin >> N >> S;

	int w = 0, b = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '.') w++;
	}

	int W = w;
	int ans = INT_MAX;
	for (int i = 0; i < S.size(); i++) {
		char c = S[i];
		if (c == '.') w--;
		if (c == '#') b++;
		ans = min(ans, w + b);
	}
	ans = min(ans, W);

	cout << ans << endl;
}