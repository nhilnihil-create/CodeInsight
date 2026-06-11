//あらためて見るとこの問題全然わからない

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

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint();
	int a[2][200000], b[2][200000];
	int kazuA[29] = {}, kazuB[29] = {};
	rep(i, N) {
		a[0][i] = getint(); 
		rep(j, 28) kazuA[j] += a[0][i] >> j & 1;
	}
	rep(i, N) {
		b[0][i] = getint();
		rep(j, 28) kazuB[j] += b[0][i] >> j & 1;
	}
	int kotae = 0;
	rep(i, 28) {
		int p = i & 1;

		int kazu[2];
		kazu[0] = 0;
		kazu[1] = N - kazuA[i];
		rep(j, N) a[!p][kazu[a[p][j] >> i & 1]++] = a[p][j];
		kazu[0] = 0;
		kazu[1] = N - kazuB[i];
		rep(j, N) b[!p][kazu[b[p][j] >> i & 1]++] = b[p][j];

		int kari = 0;
		int d = (1 << i) - 1;
		int d2 = 1 << i;
		int k1 = kazu[0];
		int k2 = N;
		rep(j, N - kazuA[i]) {
			while (k1 > 0 && (a[!p][j] & d) + (b[!p][k1 - 1] & d) >= d2) k1--;
			while (k2 > kazu[0] && (a[!p][j] & d) + (b[!p][k2 - 1] & d) >= d2) k2--;
			kari ^= k1 ^ k2;
		}
		k1 = kazu[0];
		k2 = N;
		for (int j = N - kazuA[i]; j < N; j++) {
			while (k1 > 0 && (a[!p][j] & d) + (b[!p][k1 - 1] & d) >= d2) k1--;
			while (k2 > kazu[0] && (a[!p][j] & d) + (b[!p][k2 - 1] & d) >= d2) k2--;
			kari ^= N ^ k1 ^ k2;
		}

		kotae += (kari & 1) << i;
	}

	int d2 = 1 << 28;
	int k = N;
	int kari = N;
	rep(j, N) {
		while (k > 0 && a[0][j] + b[0][k - 1] >= d2) k--;
		kari ^= k;
	}
	kotae += (kari & 1) << 28;

	printf("%d", kotae);

	Would you please return 0;
}