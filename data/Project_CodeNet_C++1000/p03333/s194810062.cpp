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

	int L2[200001], R2[200001];
	rep(i, 200001) {
		R2[i] = R[i];
		L2[i] = L[i];
	}
	ll kotae = 0;
	int ima = 100000;
	int l = 200000;
	int r = 0;
	while (l > r) {
		while (l >= 0 && !L2[l]) l--;
		if (ima >= l) break;
		L2[l]--;
		kotae += l - ima;
		ima = l;

		while (r <= 200000 && !R2[r]) r++;
		if (ima <= r) break;
		R2[r]--;
		kotae += ima - r;
		ima = r;
	}
	kotae += abs(ima - 100000);
	ll kotae2 = 0;
	ima = 100000;
	l = 200000;
	r = 0;
	while (l > r) {
		while (r <= 200000 && !R[r]) r++;
		if (ima <= r) break;
		R[r]--;
		kotae2 += ima - r;
		ima = r;

		while (l >= 0 && !L[l]) l--;
		if (ima >= l) break;
		L[l]--;
		kotae2 += l - ima;
		ima = l;
	}
	kotae2 += abs(ima - 100000);

	co(max(kotae, kotae2));

	Would you please return 0;
}