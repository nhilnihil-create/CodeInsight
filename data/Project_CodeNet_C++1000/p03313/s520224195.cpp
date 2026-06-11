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

const int dm = 1 << 22;
char dn[dm], * di = dn;
char C[10];
int keta = 0;
inline void putint(int X) {
	keta = 0;
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));
	*di++ = '\n';
}
inline void putmae() {
	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));
	*di++ = '\n';
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

	rep(k, N) {
		int m = 1 << k;
		int m1 = n - 1 << k;
		int m2 = ~m1;
		for (int p = (n >> 1) - 1; p >= 0; p--) {
			int j = ((p & m1) << 1) + (p & m2);
			int i = j | m;
			int k = min(dp1[i], dp1[j]);
			dp1[i] = max(dp1[i], dp1[j]);
			dp2[i] = max(dp2[i], k);
			dp2[i] = max(dp2[i], dp2[j]);
		}
	}

	int saidai = 0;
	rep1(i, n - 1) {
		if (saidai < dp1[i] + dp2[i]) {
			saidai = dp1[i] + dp2[i];
			putint(saidai);
		}
		else putmae();
	}
	fwrite(dn, 1, di - dn, stdout);

	Would you please return 0;
}