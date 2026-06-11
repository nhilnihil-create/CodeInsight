#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {
	long long int N, Y, x, y, z;

	cin >> N >> Y;
	
	if (Y > N * 10000 || N * 1000 > Y) {
		x = -1;
		y = -1;
		z = -1;
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			z = N - i - j;
			if (i * 10000 + j * 5000 + 1000 * z == Y && z >= 0) {
				x = i;
				y = j;
				goto Ans;
			}
		}
	}

	x = -1;
	y = -1;
	z = -1;

	Ans:
	cout << x << " " << y << " " << z;

	return 0;
}