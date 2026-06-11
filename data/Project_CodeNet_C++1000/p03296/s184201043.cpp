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

int main()
{
	int N, ans = 0;

	cin >> N;
	rep(i, N) cin >> a[i];

	repc(i, 1, N - 1) {
		if (a[i] == a[i - 1]) {
			a[i] = 500;
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
