//あらためて見るとこの問題全然わからない

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
	int A[2][200000], B[2][200000];
	int kazuA[29] = {}, kazuB[29] = {};
	rep(i, N) {
		int a = getint();
		A[0][i] = a; 
		rep(j, 28) kazuA[j] += a >> j & 1;
	}
	rep(i, N) {
		int b = getint();
		B[0][i] = b;
		rep(j, 28) kazuB[j] += b >> j & 1;
	}
	int kotae = 0;
	rep(i, 28) {
		int p = i & 1;
		auto Amae = A[p];
		auto Bmae = B[p];
		auto Atugi = A[!p];
		auto Btugi = B[!p];

		int kazu[2];
		kazu[0] = 0;
		kazu[1] = N - kazuB[i];
		rep(j, N) Btugi[kazu[Bmae[j] >> i & 1]++] = Bmae[j];

		int kazu0 = 0;
		int kazu1 = N - kazuA[i];

		int kari = N & kazuA[i] & 1;
		int d = (1 << i) - 1;
		int d2 = 1 << i;
		int k1 = N - kazuB[i];
		int k2 = N;
		int k3 = N - kazuB[i];
		int k4 = N;

		rep(j, N) {
			if (Amae[j] >> i & 1) {
				while (k1 > 0 && (Amae[j] & d) + (Btugi[k1 - 1] & d) >= d2) k1--;
				while (k2 > kazu[0] && (Amae[j] & d) + (Btugi[k2 - 1] & d) >= d2) k2--;
				kari ^= k1 ^ k2;

				Atugi[kazu1++] = Amae[j];
			}
			else {
				while (k3 > 0 && (Amae[j] & d) + (Btugi[k3 - 1] & d) >= d2) k3--;
				while (k4 > kazu[0] && (Amae[j] & d) + (Btugi[k4 - 1] & d) >= d2) k4--;
				kari ^= k3 ^ k4;

				Atugi[kazu0++] = Amae[j];
			}
		}
		kotae += (kari & 1) << i;
	}

	int d2 = 1 << 28;
	int k = N;
	int kari = N;
	rep(j, N) {
		while (k > 0 && (*A)[j] + (*B)[k - 1] >= d2) k--;
		kari ^= k;
	}
	kotae += (kari & 1) << 28;

	printf("%d", kotae);

	Would you please return 0;
}