#include <iostream>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define W 10000000
using namespace std;

int Data[W][10][3];
int V[10];

int min(int x, int y) {
	return x < y ? x : y;
}

int som(int n) {
	int t = n;
	int k = 0;
	while (t != 0){
		k += t % 10;
		t /= 10;
	}
	return k;
}

void check(int n, int m, int k, int x[3]) {
	x[2] = 1;
	if (Data[n][m][0] != 0) {
		if (Data[n][m][2] <= Data[n][m][1] + k) {
			x[2] = 0;
		} else {
			Data[n][m][2] = Data[n][m][1] + k;
		}
		Data[n][m][2] = min(Data[n][m][2], Data[n][m][1] + k);
		x[0] = Data[n][m][0];
		x[1] = Data[n][m][1];
		return;
	}
	int t = n + V[m];
	x[0] = t / 10;
	x[1] = t % 10;
	Data[n][m][0] = x[0];
	Data[n][m][1] = x[1];
	Data[n][m][2] = x[1] + k;
}

int main() {
	int N;
	std:: cin >> N;

	rep(i, 10) V[i] = i * N;

	int mi = 1000;
	rep(i, 9) mi = min(mi, som(V[i + 1]));

	int *k;
	k = (int *)malloc(sizeof(int) * W * 2);
	int cnt = 0;
	rep(i, 9) {
		int x[3];
		check(0, i + 1, 0, x);
		if (x[1] < mi - 1) {
			k[cnt * 2] = x[0];
			k[cnt * 2 + 1] = x[1];
			cnt += 1;
		}
	}

	int *P;
	P = k;
	while (cnt != 0) {
		k = (int *)malloc(sizeof(int) * W * 2);
		int kc = 0;
		rep(i, cnt) {
			int t = som(P[i * 2]);
			mi = min(mi, t + P[i * 2 + 1]);
			rep(j, 10) {
				int x[3];
				check(P[i * 2], j, P[i * 2 + 1], x);
				if (x[2] == 1 && x[1] + P[i * 2 + 1] < mi - 1) {
					k[kc * 2] = x[0];
					k[kc * 2 + 1] = x[1] + P[i * 2 + 1];
					kc += 1;
				}
			}
		}
		cnt = kc;
		free(P);
		P = k;
	}
	std:: cout << mi << endl;
}