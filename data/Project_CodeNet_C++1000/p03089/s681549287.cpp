#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int main() {
	int N; cin >> N;
	vector<int> b(N),a(N,0);
	vector<bool> z(N, 0);
	for (int i = 0; i < N; i++)cin >> b[i];
	for (int i = 0; i < N; i++) {
		int x = N - i-1;
		for (int j = 0; j < N; j++) {
			if (z[N - 1 - j] == 1)continue;
			if (x+1 == b[N - j - 1]) {
				a[N-i-1] = b[N - 1 - j];
				z[N - 1 - j] = 1;
				break;
			}
			x--;
		}
		if (a[N-1-i] == 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 0; i < N; i++)cout << a[i] << endl;
}



