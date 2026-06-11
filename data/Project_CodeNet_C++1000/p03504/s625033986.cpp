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

int cnt[31][100002];
int num[100001];

int main()
{
	int N, C, ans = 0;

	cin >> N >> C;
	rep(i, N) {
		int s, t, c;
		cin >> s >> t >> c;

		repc(j, s, t) cnt[c][j] = 1;
	}

	repc(i, 1, 100000) repc(j, 1, C) num[i] += cnt[j][i];
	repc(i, 1, 100000) ans = max(ans, num[i]);

	cout << ans << endl;

	return 0;
}
