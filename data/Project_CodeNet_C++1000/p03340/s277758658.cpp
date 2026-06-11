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

int A[200000];
int bits[200000][20];
int sum[20];

int main()
{
	int N, from = 0, len = 0;
	ll ans = 0;

	cin >> N;
	rep(i, N) cin >> A[i];

	int SHIFT = 0;
	rep(j, 20) {
		rep(i, N) {
			bits[i][j] = (A[i] >> SHIFT) & 1;
		}
		SHIFT++;
	}

	rep(to, N) {
		rep(loop, 20) sum[loop] += bits[to][loop];
		len++;

		repc(i, from, to - 1) {
			bool f = true;
			rep(loop, 20) if (sum[loop] > 1) f = false;
			if (f) break;

			rep(loop, 20) sum[loop] -= bits[i][loop];
			len--;
			from++;
		}

		ans += len;
	}

	cout << ans << endl;

	return 0;
}
