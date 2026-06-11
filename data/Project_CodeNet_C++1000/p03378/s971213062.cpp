#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	int N, M, X, a, costL=0, costR=0;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> a;
		if (a < X) costL++;
		else costR++;
	}
	cout << min(costL, costR) << endl;
}