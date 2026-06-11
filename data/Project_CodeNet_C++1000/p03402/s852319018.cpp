#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

char ans[101][101];

int main()
{
	int A, B, cntA = 1, cntB = 1;

	cin >> A >> B;

	repc(i, 1, 100) {
		repc(j, 1, 50) ans[i][j] = '#';
		repc(j, 51, 100) ans[i][j] = '.';
	}

	for (int i = 1; i <= 100; i += 2) {
		if (cntA >= A) break;
		for (int j = 2; j <= 48; j += 2) {
			if (cntA >= A) break;
			ans[i][j] = '.';
			cntA++;
		}
	}

	for (int i = 1; i <= 100; i += 2) {
		if (cntB >= B) break;
		for (int j = 52; j <= 98; j += 2) {
			if (cntB >= B) break;
			ans[i][j] = '#';
			cntB++;
		}
	}

	puts("100 100");
	repc(i, 1, 100) {
		repc(j, 1, 100) cout << ans[i][j];
		cout << endl;
	}

	return 0;
}
