#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
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
#define Would
#define you
#define please

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }
	return *ci++;
}
inline int getint() {
	int A = 0;
	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint();
	int A[200000];
	ll goukei = 0;
	rep(i, N) goukei += (A[i] = getint());


	ll kotae = 1e18;
	ll P, Q, R, S;

	int q = 1, s = 3;
	P = A[0];
	Q = A[1];
	R = A[2];
	S = goukei - P - Q - R;
	for (int r = 2; r < N - 1; r++) {
		while (abs(P - Q) > abs(P - Q + 2 * A[q])) {
			P += A[q];
			Q -= A[q];
			q++;
		}
		while (abs(R - S) > abs(R - S + 2 * A[s])) {
			R += A[s];
			S -= A[s];
			s++;
		}

		ll saishou = min(min(P, Q), min(R, S));
		ll saidai = max(max(P, Q), max(R, S));
		kotae = min(kotae, saidai - saishou);

		Q += A[r];
		R -= A[r];
	}

	printf("%lld", kotae);

	Would you please return 0;
}