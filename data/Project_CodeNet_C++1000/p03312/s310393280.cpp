//#include<bits/stdc++.h>
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

	int q = 1, s = 3;
	ll P[4];
	P[0] = A[0];
	P[1] = A[1];
	P[2] = A[2];
	P[3] = goukei - P[0] - P[1] - P[2];
	for (int r = 2; r < N - 1; r++) {
		while (abs(P[0] - P[1]) > abs(P[0] - P[1] + 2 * A[q])) {
			P[0] += A[q];
			P[1] -= A[q];
			q++;
		}
		while (abs(P[2] - P[3]) > abs(P[2] - P[3] + 2 * A[s])) {
			P[2] += A[s];
			P[3] -= A[s];
			s++;
		}
		ll kari = *max_element(P, P + 4) - *min_element(P, P + 4);
		kotae = min(kotae, kari);

		P[1] += A[r];
		P[2] -= A[r];
	}

	printf("%lld", kotae);

	Would you please return 0;
}