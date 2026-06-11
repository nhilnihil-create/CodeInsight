#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define Would
#define you
#define please

ll mod = 1e9 + 7;

ll mpow(ll A, ll B) {
	if (B == 0) return 1;
	else if (B == 1) return A;
	else if (B % 2) return A * mpow(A, B - 1) % mod;
	else {
		ll hanbun = mpow(A, B / 2);
		return hanbun * hanbun % mod;
	}
}

ll mdiv(ll A, ll B) {
	return A * mpow(B, mod - 2) % mod;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	//解説みました

	int N;
	cin >> N;
	ll A[100000];
	rep(i, N) cin >> A[i];
	
	ll kaijou = 1;
	rep1(i, N) {
		kaijou = kaijou * i % mod;
	}

	ll B[100001] = {};
	rep1(i, N) {
		B[i] = (B[i - 1] + mdiv(kaijou, i)) % mod;
	}
	
	ll kotae = 0;
	rep1(i, N) {
		ll tasu = A[i - 1] * (B[i] + B[N - i + 1] - B[1] + mod) % mod;
		kotae = (kotae + tasu) % mod;
	}

	co(kotae);

	Would you please return 0;
}