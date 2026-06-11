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
	char S[1000000];
	fread(S, 1, N + 4 * Q, stdin);
	int L = 0;
	int R = N;
	char *t = S + N + 4 * Q - 3;
	char *d = S + N + 4 * Q - 1;

	for (int i = Q - 1; i >= 0; i--) {
		if (*d == 'R') {
			if (R > 0 && *(S + R - 1) == *t) R--;
			if (L > 0 && *(S + L - 1) == *t) L--;
		}
		else {
			if (R < N && *(S + R) == *t) R++;
			if (L < N && *(S + L) == *t) L++;
		}
		t -= 4;
		d -= 4;
	}

	co(R - L);

	Would you please return 0;
}