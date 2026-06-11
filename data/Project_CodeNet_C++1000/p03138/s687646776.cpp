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
	ll N, K;
	cin >> N >> K;

	vector<int> kbi(61);
	ll temp = K;
	int idm = 0;
	for (int i = 0; temp > 0; i++) {
		kbi[i] = temp % 2;
		temp /= 2;
		idm = i;
	}

	vector<int> asum(61);
	for (int i = 0; i < N; i++) {
		ll a;
		cin >> a;
		
		for (int j = 0; a > 0; j++) {
			asum[j] += a % 2;
			a /= 2;
		}
	}

	ll ans = 0;
	ll twos = pow(2, 60);

	bool flag = false;
	for (int i = 60; i >= 0; i--) {
		int zeros = N - asum[i];
		if (asum[i] >= zeros) {
			if (kbi[i] == 1) flag = true;
			ans += asum[i] * twos;
		}
		else {
			if (flag || i == idm&&kbi[i]||kbi[i])
				ans += zeros * twos;
			else
				ans += asum[i] * twos;
		}
		twos /= 2;
	}

	cout << ans << endl;
}
