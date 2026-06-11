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

void pakuri_sort(int N, int A[]) {
	const int b = 8;
	int tmp[100001];
	rep(k, 4) {
		int kazu[1 << b] = {}, kazu2[1 << b] = {};
		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;
		rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];
		for (int i = N - 1; i >= 0; i--) tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];
		k++;
		rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;
		rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];
		for (int i = N - 1; i >= 0; i--) A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];
	}
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	int N = getint(), K = getint();
	int saidai[100000] = {};
	int shurui = 0;
	int sonota[100001];
	int k = 0;
	rep(i, N) {
		int t = getint() - 1;
		int d = getint();
		if (!saidai[t]) {
			shurui++;
			saidai[t] = d;
		}
		else {
			if (saidai[t] < d) {
				swap(saidai[t], d);
			}
			sonota[k++] = d;
		}
	}

	pakuri_sort(100000, saidai);
	pakuri_sort(k, sonota);

	ll sonota2[100000];
	sonota2[k - 1] = sonota[k - 1];
	for (int i = k - 1; i >= 1; i--) {
		sonota2[i - 1] = sonota2[i] + sonota[i - 1];
	}

	ll kari = 0;
	ll kotae = 0;
	for (int i = 1; i <= min(K, shurui); i++) {
		kari += saidai[100000 - i];
		ll kari2 = kari;
		if (K - i > 0 && 0 <= k - K + i) kari2 += sonota2[k - K + i];
		kari2 += 1ll * i * i;
		kotae = max(kotae, kari2);
	}

	printf("%lld", kotae);

	Would you please return 0;
}