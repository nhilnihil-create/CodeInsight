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

int r[5], c[4];

int main()
{
	int a, b;

	rep(i, 3) {
		cin >> a >> b;
		r[a]++;
		r[b]++;
	}

	repc(i, 1, 4) c[r[i]]++;

	if (c[1] == 2 && c[2] == 2) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
