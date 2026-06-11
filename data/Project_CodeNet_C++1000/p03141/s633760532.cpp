#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)


struct E {
	int p;
	int a;
	int b;
	bool operator<(const E &left) const {

		return p < left.p;
	}
};

int main() {
	int n;
	cin >> n;
	
	vector<E> es(n);
	rep(i , n) {
		int a, b;

		cin >> a >> b;
		E e;
		e.p = abs(a + b);
		e.a = a;
		e.b = b;
		es.push_back(e);
	}

	sort(es.rbegin(), es.rend());


	ll ans = 0;

	rep(i, n) {
		if (i % 2 == 0) {
			ans += (ll) es[i].a;
		} else {
			ans -= (ll) es[i].b;
		}
		
	}

	cout << ans << endl;

	return 0;
}