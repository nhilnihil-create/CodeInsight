#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
//#include <cassert>
#include <vector>
//#include <array>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <stack>
//#include <queue>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP1(i, n) for (int i = 1; i <= (int)(n); i++)
using ll = long long;
using namespace std;

#define MAXN 1000

int main() {
	const int m = 31;
	const ll maxu = (ll)pow(2, m) - 1;

	int N;
	cin >> N;
	unsigned int U[MAXN + 1], V[MAXN + 1];
	bool is_even;

	REP1(i_arm, N) {
		int X, Y;
		cin >> X >> Y;
		if (i_arm == 1) {
			is_even = ((X + Y) % 2 == 0);
		}
		else {
			if (!(is_even == ((X + Y) % 2 == 0))) {
				cout << -1 << endl;
				return 0;
			}
		}
		U[i_arm] = (unsigned int)((((ll)X + Y) + maxu) / 2);
		V[i_arm] = (unsigned int)((((ll)X - Y) + maxu) / 2);
	}

	int m_ans = m;
	if (is_even)
		m_ans++;
	cout << m_ans << endl;
	REP(j, m) {
		cout << (ll)pow(2, j) << " ";
	}
	if (is_even) {
		cout << 1;
	}
	cout << endl;
	REP1(i, N) {
		int u = U[i];
		int v = V[i];
		REP(j, m) {
			char c;
			if ((u & 1) == 1) {
				if ((v & 1) == 1) {
					c = 'R';
				}
				else {
					c = 'U';
				}
			}
			else {
				if ((v & 1) == 1) {
					c = 'D';
				}
				else {
					c = 'L';
				}
			}
			cout << c;
			u = u >> 1;
			v = v >> 1;
		}
		if (is_even) {
			cout << 'R';
		}
		cout << endl;
	}

	return 0;
}