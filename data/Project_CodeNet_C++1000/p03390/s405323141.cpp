//ProblemD

#ifdef _MYPC
#include "mypc.h"
#endif // _MYPC

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>
#include <complex>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

//ProblemD

using ll = long long;

class Solve {
private:
	void solve() {
		int Q;
		cin >> Q;
		ll a, b;
		for (int qq = 0; qq < Q; qq++) {
			cin >> a >> b;
			ll p = a * b - 1;

			ll q = (ll)sqrt(p);
			while ((q + 1) * (q + 1) <= p) q = q + 1;
			while (q * q > p) q --;

			if (q == 0) {
				cout << 0 << endl;
				continue;
			}

			ll rst = 2 * q - 1;
			ll ne = q;
			if (q * (q + 1) <= p) {
				rst++;
				ne++;
			}

			auto uni = [&](ll x) -> ll {
				if (x <= q) return 1;
				ll s = p / x;
				if (s == 0) return 0;
				if (s + x > q + ne) return 0;
				if (p / s > x) return 0;
				return 1;
			};
			rst -= uni(a);
			rst -= uni(b);

			cout << rst << endl;
		}
	}

public:
	Solve() { solve(); }
};

int main(int argc, char* argv[]) {
	unique_ptr<Solve> solve = make_unique<Solve>();
	return 0;
}
