#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define getchar getchar_unlocked
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

const int cm = 1 << 17;
char ci[cm];
char *cn = ci + cm;
inline char getcha() {
	if (cn - ci == cm) { fread(ci, 1, cm, stdin); cn = ci; }
	return *cn++;
}

int getint() {
	char C;
	while (!isdigit(C = getchar()));
	int x = C - '0';
	while (isdigit(C = getchar())) x = x * 10 + C - '0';
	return x;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, Q;
	N = getint();
	Q = getint();
	char S[200000];
	fread(S, 1, N, stdin);
	char T[200000], D[200000];
	rep(i, Q) {
		getcha();
		T[i] = getcha();
		getcha();
		D[i] = getcha();;
	}
	int L = 0;
	int R = N;
	for (int i = Q - 1; i >= 0; i--) {
		if (R > 0 && D[i] == 'R' && S[R - 1] == T[i]) R--;
		else if (R < N && D[i] == 'L' && S[R] == T[i]) R++;
		if (L > 0 && D[i] == 'R' && S[L - 1] == T[i]) L--;
		else if (L < N && D[i] == 'L' && S[L] == T[i]) L++;
	}

	co(R - L);

	Would you please return 0;
}