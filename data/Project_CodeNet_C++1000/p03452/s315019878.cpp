//#include<bits/stdc++.h>
#include<cstdio>
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
char cn[cm], * ci = cn + cm;
inline char getcha() {
	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }
	return *ci++;
}
inline int getint() {
	char C = getcha();
	int A = C - '0';
	while ((C = getcha()) >= '0') A = A * 10 + C - '0';
	return A;
}

const int x = (1 << 30) - 1;

int P[100001];
int D[100001];
ll Find(int A) {
	if (P[A] < 0) return A;

	ll k = Find(P[A]);
	int d = k >> 30;
	int p = k & x;
	D[A] += d;
	P[A] = p;

	return ((ll)(unsigned)D[A] << 30) + p;
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint();
	int M = getint();
	rep1(i, N) P[i] = -1;

	int OK = 1;
	rep(i, M) {
		int L = getint();
		int R = getint();
		int d = getint();

		ll k = Find(L);
		int dl = k >> 30;
		int l = k & x;
		k = Find(R);
		int dr = k >> 30;
		int r = k & x;

		if (l != r) {
			if (P[l] <= P[r]) {
				P[l] += P[r];
				P[r] = l;
				D[r] = dl - dr + d;
			}
			else {
				P[r] += P[l];
				P[l] = r;
				D[l] = dr - dl - d;
			}
		}
		else {
			if (dl + d != dr) {
				OK = 0;
				break;
			}
		}
	}
	if (OK) printf("Yes");
	else printf("No");

	Would you please return 0;
}