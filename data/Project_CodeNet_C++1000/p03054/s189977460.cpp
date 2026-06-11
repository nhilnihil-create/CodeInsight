#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int mod = 1e9 + 7, INF = 1e9;


int main(void) {
	int h, w, n, si, sj, i, pi1, pi2, pj1, pj2;
	string s, t;

	scanf("%d%d%d%d%d", &h, &w, &n, &si, &sj);
	cin >> s >> t;

	pi1 = 1;
	pi2 = h + 1;
	pj1 = 1;
	pj2 = w + 1;
	for (i = n - 1; i >= 0; i--) {
		if (t[i] == 'L') pj2 = min(w + 1, pj2 + 1);
		if (t[i] == 'R') pj1 = max(1, pj1 - 1);
		if (t[i] == 'U') pi2 = min(h + 1, pi2 + 1);
		if (t[i] == 'D') pi1 = max(1, pi1 - 1);

		if (s[i] == 'L') pj1 = min(w + 1, pj1 + 1);
		if (s[i] == 'R') pj2 = max(1, pj2 - 1);
		if (s[i] == 'U') pi1 = min(h + 1, pi1 + 1);
		if (s[i] == 'D') pi2 = max(1, pi2 - 1);

		if (pi1 >= pi2 || pj1 >= pj2) {
			printf("NO\n");
			return 0;
		}
	}

	if (pi1 <= si && si < pi2 && pj1 <= sj && sj < pj2) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	return 0;
}