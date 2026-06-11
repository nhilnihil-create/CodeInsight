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
	const int M = 31;

	int n;
	cin >> n;
	int u[MAXN + 1], v[MAXN + 1];
	bool is_even;
	int m = 1;
	REP1(i_point, n) {
		int x, y;
		cin >> x >> y;
		if (i_point == 1) {
			is_even = ((x + y) % 2 == 0);
		}
		else {
			if (is_even != ((x + y) % 2 == 0)) {
				cout << -1 << endl;
				return 0;
			}
		}
		u[i_point] = x + y;
		v[i_point] = x - y;
		if (is_even) {
			u[i_point]--;
			v[i_point]--;
		}
		for (int k = 1; k <= M; k++) {
			const ll tptk = (ll)1 << k;
			if ((-tptk < u[i_point] && u[i_point] < tptk && -tptk < v[i_point] && v[i_point] < tptk)) {
				m = max(m, k); 
				break;
			}
		}
	}

	const int maxu = (1 << m) - 1;
	int m_ans = m;
	if (is_even)
		m_ans++;
	cout << m_ans << endl;
	REP(j_arm, m) {
		cout << (1 << j_arm) << " ";
	}
	if (is_even) {
		cout << 1;
	}
	cout << endl;
	REP1(i_point, n) {
		unsigned int tmpu = (u[i_point] + maxu) / 2;
		unsigned int tmpv = (v[i_point] + maxu) / 2;
		REP(j_arm, m) {
			char c;
			if ((tmpu & 1) == 1) {
				if ((tmpv & 1) == 1) {
					c = 'R';
				}
				else {
					c = 'U';
				}
			}
			else {
				if ((tmpv & 1) == 1) {
					c = 'D';
				}
				else {
					c = 'L';
				}
			}
			cout << c;
			tmpu >>= 1;
			tmpv >>= 1;
		}
		if (is_even) {
			cout << 'R';
		}
		cout << endl;
	}

	return 0;
}