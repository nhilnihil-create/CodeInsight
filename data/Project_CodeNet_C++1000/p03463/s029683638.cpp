#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int n, a, b; cin >> n >> a >> b;

	while (true) {
		// Move A
		if (b != a + 1) {
			a++;
		} else {
			if (a == 1) {
				cout << "Borys" << endl;
				return 0;
			} else {
				a--;
			}
		}

		// Move B
		if (b != a + 1) {
			b--;
		} else {
			if (b == n) {
				cout << "Alice" << endl;
				return 0;
			} else {
				b++;
			}
		}
	}
}
