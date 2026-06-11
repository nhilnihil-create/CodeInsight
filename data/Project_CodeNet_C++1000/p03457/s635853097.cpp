#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}


bool check(int dt, int dx, int dy) {
	int diff = abs(dx) + abs(dy);
	return (dt >= diff) && (dt - diff) % 2 == 0;
}
int main() {
	int N, pt=0, px=0, py=0, t, x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t >> x >> y;
		bool ok = check(t-pt, x - px, y - py);
		if (ok) {
			pt = t;
			px = x;
			py = y;
		}
		else {
			print("No");
			return 0;
		}
	}
	print("Yes");
}