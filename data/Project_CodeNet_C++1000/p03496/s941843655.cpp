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

int a[51];

int main()
{
	int N, absmax = 1;

	cin >> N;
	repc(i, 1, N) cin >> a[i];

	repc(i, 2, N) {
		if (abs(a[absmax]) < abs(a[i])) absmax = i;
	}

	if (a[absmax] > 0) {
		cout << N * 2 << endl;
		repc(i, 1, N) {
			if (i == 1) {
				cout << absmax << ' ' << i << endl;
				cout << absmax << ' ' << i << endl;
			}
			else {
				cout << i - 1 << ' ' << i << endl;
				cout << i - 1 << ' ' << i << endl;
			}
		}
	}
	else if (a[absmax] < 0) {
		cout << N * 2 << endl;
		rrepc(i, N, 1) {
			if (i == N) {
				cout << absmax << ' ' << i << endl;
				cout << absmax << ' ' << i << endl;
			}
			else {
				cout << i + 1 << ' ' << i << endl;
				cout << i + 1 << ' ' << i << endl;
			}
		}
	}
	else {
		cout << 0 << endl;
	}

	return 0;
}
