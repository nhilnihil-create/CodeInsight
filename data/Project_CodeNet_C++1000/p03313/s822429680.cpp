//お勉強中

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

inline void keisan(int &a, int &b, int c, int d) {
	int k = min(a, c);
	a = max(a, c);
	b = max(b, k);
	b = max(b, d);
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint();
	int n = 1 << N;
	int dp1[1 << 18], dp2[1 << 18];
	rep(i, n) {
		dp1[i] = getint();
		dp2[i] = 0;
	}

	rep(j, N) {
		for (int i = n - 1; i >= 0; i--) {
			if (i >> j & 1) keisan(dp1[i], dp2[i], dp1[i & ~(1 << j)], dp2[i & ~(1 << j)]);
		}
	}

	int saidai = 0;
	rep1(i, n - 1) {
		saidai = max(saidai, dp1[i] + dp2[i]);
		printf("%d\n", saidai);
	}

	Would you please return 0;
}