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
	char S[200000];
	fread(S, 1, N, stdin);
	char T[200000][4];
	fread(T, 1, 4 * Q, stdin);
	int L = 0;
	int R = N;
	for (int i = Q - 1; i >= 0; i--) {
		if (R > 0 && T[i][3] == 'R' && S[R - 1] == T[i][1]) R--;
		else if (R < N && T[i][3] == 'L' && S[R] == T[i][1]) R++;
		if (L > 0 && T[i][3] == 'R' && S[L - 1] == T[i][1]) L--;
		else if (L < N && T[i][3] == 'L' && S[L] == T[i][1]) L++;
	}

	co(R - L);

	Would you please return 0;
}