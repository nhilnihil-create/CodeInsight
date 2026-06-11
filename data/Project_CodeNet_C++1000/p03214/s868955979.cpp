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
#define EPS (1e-15)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define bet(x, a, b) (a) <= (x) && (x) < (b)
typedef long long ll;
typedef unsigned long long ull;

int a[100];

int main()
{
	int N, ans = 0, avg = 0, diff = 1000000;

	cin >> N;
	rep(i, N) cin >> a[i];

	rep(i, N) {
		avg += a[i];
		a[i] *= N;
	}

	rep(i, N) {
		if (abs(a[i] - avg) < diff) {
			ans = i;
			diff = abs(a[i] - avg);
		}
	}

	cout << ans << endl;

	return 0;
}
