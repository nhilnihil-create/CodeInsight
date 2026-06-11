#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please


int L[200001], R[200001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;

	rep(i, N) {
		int l, r;
		cin >> l >> r;
		L[l + 100000]++;
		R[r + 100000]++;
	}

	ll kotae = -200000, kotae2 = 0;
	int l = 200000;
	int r = 0;

	while (l > r) {
		kotae += (l - r);
		while (r <= 200000 && !R[r]) r++;
		while (l >= 0 && !L[l]) l--;
		R[r]--;
		L[l]--;
		if (kotae2 < kotae + max(100000 - r, l - 100000)) {
			kotae2 = kotae + max(100000 - r, l - 100000);
		}
	}

	co(2 * max(kotae, kotae2));

	Would you please return 0;
}