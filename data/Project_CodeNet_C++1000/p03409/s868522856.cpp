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

int a[100];
int b[100];
int c[100];
int d[100];
int f[100];
pair<int, int> blue[100];

int main()
{
	int N, ans = 0;

	cin >> N;
	rep(i, N) cin >> a[i] >> b[i];
	rep(i, N) cin >> blue[i].first >> blue[i].second;

	sort(blue, blue + N);
	rep(i, N) c[i] = blue[i].first, d[i] = blue[i].second;

	rep(i, N) {
		int ymax = -1;
		int index = -1;

		rep(j, N) {
			if (f[j]) continue;
			if (a[j] < c[i] && b[j] < d[i] && b[j] > ymax) {
				index = j;
				ymax = b[j];
			}
		}

		if (index == -1) continue;

		f[index] = true;
		ans++;
	}

	cout << ans << endl;

	return 0;
}