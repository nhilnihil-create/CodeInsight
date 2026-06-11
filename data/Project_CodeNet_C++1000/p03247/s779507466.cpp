#include <cstdio>

const int MN = 1005;

int N;
int X[MN][20], Y[MN][20];

inline void V(int *A) {
	static int _[3] = {0, 1, -1};
	int x = A[0];
	for (int j = 0; j <= 19; ++j) {
		A[j] = _[(x % 3 + 3) % 3];
		x = (x - A[j]) / 3;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d%d", &X[i][0], &Y[i][0]);
	for (int i = 1; i <= N; ++i) if ((X[i][0] ^ Y[i][0] ^ X[1][0] ^ Y[1][0]) & 1) return puts("-1"), 0;
	int O = (X[1][0] ^ Y[1][0]) & 1;
	for (int i = 1; i <= N; ++i) V(X[i]), V(Y[i]);
	printf("%d\n", O ? 39 : 40);
	for (int j = 0, x = 1; j <= 19; ++j, x *= 3) {
		if (j == 19) {
			if (O) printf("%d\n", x);
			else printf("%d %d\n", x, x);
		} else printf("%d %d ", x, x);
	}
	for (int i = 1; i <= N; ++i) {
		int *x = X[i], *y = Y[i];
		for (int j = 0; j <= 19; ++j) {
			if (x[j] == 2) x[j] = -1, ++x[j + 1];
			if (x[j] == -2) x[j] = 1, --x[j + 1];
			if (y[j] == 2) y[j] = -1, ++y[j + 1];
			if (y[j] == -2) y[j] = 1, --y[j + 1];
			if (j == 19 && O) {
				if (x[j]) printf("%c", ~x[j] ? 'R' : 'L'), x[j] = 0;
				if (y[j]) printf("%c", ~y[j] ? 'U' : 'D'), y[j] = 0;
			} else if (!x[j] && !y[j]) printf("RL");
			else if (x[j] && y[j]) printf("%c%c", ~x[j] ? 'R' : 'L', ~y[j] ? 'U' : 'D'), x[j] = y[j] = 0;
			else if (x[j]) printf("%s", ~x[j] ? "LL" : "RR"), x[j + 1] += x[j], x[j] = 0;
			else if (y[j]) printf("%s", ~y[j] ? "DD" : "UU"), y[j + 1] += y[j], y[j] = 0;
		} puts("");
	}
	return 0;
}