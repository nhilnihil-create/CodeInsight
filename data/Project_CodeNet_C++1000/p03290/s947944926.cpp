#include <iostream>
#include <algorithm> // min()
#include <string>
#include <vector>
#include <climits> // INT_MAX
#include <cmath> // ceil()
#define rep(i, n) for (int i = 0; i < n; ++i)

using namespace std;
using ll = long long;
const int INF = INT_MAX;

int p[11];
int c[11];

int main() {
	int d, g;
	cin >> d >> g;
	
	rep(i, d) cin >> p[i] >> c[i];

	int ans = INF;
	for (int bit = 0; bit < (1 << d); ++bit) {
		int score = 0, num = 0, no_selected = 0;
		rep(i, d) {
			if ((1 << i) & bit) {
				score += 100 * (i + 1) * p[i] + c[i];
				num += p[i];
			}
			else {
				no_selected = i;
			}
		}

		if (score < g) {
			int base_score = 100 * (no_selected + 1);
			int need_plb_num = (g - score + base_score - 1) / base_score; // うまいこと切り上げできるように-1する
			if (need_plb_num >= p[no_selected]) {
				continue;
			}
			num += need_plb_num;
		}

		ans = min(ans, num);
	}

	cout << ans << endl;

}
