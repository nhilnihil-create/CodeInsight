#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <set>

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }

int main() {
	ll K, A, B;
	cin >> K >> A >> B;
	if (B - A < 2 || A > K) {
		print(K+1);
	}
	else {
		ll ans = A;
		K -= A-1;
		if (K % 2 == 1) {
			ans++;
			K--;
		}

		ans += (B - A) * (K / 2);
		print(ans);
	}
}
