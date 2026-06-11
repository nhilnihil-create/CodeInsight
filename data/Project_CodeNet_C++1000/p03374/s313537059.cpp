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
#define Would
#define you
#define please

const int cm = 1 << 17;
char cn[cm], *ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }
	return *ci++;
}
inline ll getint() {
	ll A = 0;
	if (ci - cn + 20 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N = getint();
	ll L = getint();
	ll X[100000];
	int V[100000];
	ll A[100001], B[100001], C, D;
	*A = 0;
	*B = 0;
	C = 0;
	D = 0;
	ll mae = 0;
	ll maeA = 0;
	ll maeB = 0;
	rep(i, N) {
		*(X + i) = getint();
		*(V + i) = getint();
		maeA = maeA + *(V + i) - *(X + i) + mae;
		*(A + i + 1) = max(*(A + i), maeA);
		maeB = maeB + *(V + i) - (*(X + i) - mae) * 2;
		*(B + i + 1) = max(*(B + i), maeB);
		mae = *(X + i);
	}
	mae = L;
	maeA = 0;
	maeB = 0;
	ll kotae = max(*(A + N), *(B + N));
	rep1(i, N) {
		maeA = maeA + *(V + N - i) + *(X + N - i) - mae;
		C = max(C, maeA);
		kotae = max(kotae, *(B + N - i) + C);
		maeB = maeB + *(V + N - i) + (*(X + N - i) - mae) * 2;
		D = max(D, maeB);
		kotae = max(kotae, *(A + N - i) + D);
		mae = *(X + N - i);
	}

	co(kotae);

	Would you please return 0;
}