#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N; cin >> N;
	bool flag = false;
	for (ll h = 1; h <= 3500&&!flag; h++) {
		for (ll n = 1; n <= 3500; n++) {
			ll u = N * n * h, d = 4 * h * n - N * n - N * h;
			if (d > 0 && u % d == 0 ) {
				cout << h << " " << n << " " << u / d << endl;
				flag = true;
				break;
			}
		}
	}

}