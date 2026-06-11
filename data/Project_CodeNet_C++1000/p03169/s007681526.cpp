#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FASTIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long int
#define F first
#define S second
#define pll pair<ll,ll>
#define vl vector<ll>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vpii vector<pair<int,int> >
#define vvpii vector<vpii >
#define vpll vector<pair<ll,ll> >
#define vvpll vector<vpll >
#define pb push_back
#define MOD 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

struct compare {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		if ((a.S - a.F) != (b.S - b.F)) return ((a.S - a.F) > (b.S - b.F));
		else return (a.F < b.F);
	}
};

const int mx = 305;
double p[mx][mx][mx], ev[mx][mx][mx];
int n;

int main() {
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
	FASTIO;
	cin >> n;
	vi cnt(4);
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		cnt[temp]++;
	}
	p[ cnt[1]][cnt[2]][cnt[3]] = 1;
	for (int c = n; c >= 0; c--) {
		for (int b = n; b >= 0; b--) {
			for (int a = n; a >= 0; a--) {
				if (a == 0 && b == 0 && c == 0) continue;
				if (a + b + c > n) continue;
				double p_waste = (double)(n - (a + b + c)) / n;
				ev[a][b][c] += p_waste / (1 - p_waste) * p[a][b][c];
				if (a != 0) {
					p[a - 1][b][c] += p[a][b][c] * a / (a + b + c);
					ev[a - 1][b][c] += ev[a][b][c] * a / (a + b + c);
				}
				if (b != 0) {
					p[a + 1][b - 1][c] += p[a][b][c] * b / (a + b + c);
					ev[a + 1][b - 1][c] += ev[a][b][c] * b / (a + b + c);
				}
				if (c != 0) {
					p[a][b + 1][c - 1] += p[a][b][c] * c / (a + b + c);
					ev[a][b + 1][c - 1] += ev[a][b][c] * c / (a + b + c);
				}
			}
		}
	}
	double ans = ev[0][0][0] + cnt[1] + 2 * cnt[2] + 3 * cnt[3];
	// cout << ev[0][0][0] + cnt[1] + 2 * cnt[2] + 3 * cnt[3] << endl;
	printf("%.10lf\n", ans);

}