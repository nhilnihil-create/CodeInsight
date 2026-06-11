#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
	int N, A, B, C;
	cin >> N >> A >> B >> C;

	vector<int> L(N);
	for (int i = 0; i < N; i++)
		cin >> L[i];

	int mx = pow(4, N);
	int ans = 1e5;
	for (int i = 0; i < mx; i++) {
		vector<int> bit(N);
		int temp = i;
		for (int j = 0; temp > 0; j++) {
			bit[j] = temp % 4;
			temp /= 4;
		}
		int a = 0, b = 0, c = 0;
		int fa = 0, fb = 0, fc = 0;
		int cost = 0;
		for (int k = 0; k < N; k++) {
			if (bit[k] == 0) {
				a += L[k];
				fa++;
				if (fa >= 2)
					cost += 10;
			}
			if (bit[k] == 1) {
				b += L[k];
				fb++;
				if (fb >= 2)
					cost += 10;
			}
			if (bit[k] == 2) {
				c += L[k];
				fc++;
				if (fc >= 2)
					cost += 10;
			}

			
		}
		if (!fa || !fb || !fc) continue;
		cost += abs(A - a) + abs(B - b) + abs(C - c);
		ans = min(ans, cost);
		//cout << "cost=" << cost << endl;
	}

	cout << ans << endl;
}
