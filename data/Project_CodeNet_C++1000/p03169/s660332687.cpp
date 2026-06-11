#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FASTIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long int


// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

// struct compare {
// 	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
// 		if ((a.S - a.F) != (b.S - b.F)) return ((a.S - a.F) > (b.S - b.F));
// 		else return (a.F < b.F);
// 	}
// };

const int mx = 305;
double ev[mx][mx][mx];
int n;

double calc(int a, int b, int c) {
	if (ev[a][b][c] != -1) return ev[a][b][c];
	double ans = 0;
	if (a != 0) {
		ans += (double)a / n * calc(a - 1, b, c);
	}
	if (b != 0) {
		ans += (double)b / n * calc(a + 1, b - 1, c);
	}
	if (c != 0) {
		ans += (double)c / n * calc(a , b + 1, c - 1);
	}
	ans += 1;
	ans *= (double)n / (a + b + c);
	ev[a][b][c] = ans;
	return ans;
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	FASTIO;
	cin >> n;
	vector<int> cnt(4);
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		cnt[temp]++;
	}
	for (int i = 0; i < mx; i++) {
		for (int j = 0; j < mx; j++) {
			for (int k = 0; k < mx; k++) {
				ev[i][j][k] = -1;
			}
		}
	}
	ev[1][0][0] = n;
	ev[0][0][0] = 0;
	double ans = calc(cnt[1], cnt[2], cnt[3]);
	printf("%.10lf\n", ans);

}