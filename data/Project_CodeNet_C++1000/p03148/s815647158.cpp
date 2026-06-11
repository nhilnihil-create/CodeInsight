#include<bits/stdc++.h>
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
void pakuri_sort2(int N, ll A[]) {
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
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	int saidai[100000] = {};
	int shurui = 0;
	ll sonota[100001];
	int k = 0;
	rep(i, N) {
		int t, d;
		cin >> t >> d;
		t--;
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
	pakuri_sort2(k, sonota);

	for (int i = k - 1; i >= 1; i--) {
		sonota[i - 1] += sonota[i];
	}

	ll kari = 0;
	ll kotae = 0;
	for (int i = 1; i <= min(K, shurui); i++) {
		kari += saidai[100000 - i];
		ll kari2 = kari;
		if (K - i > 0 && 0 <= k - K + i) kari2 += sonota[k - K + i];
		kari2 += 1ll * i * i;
		kotae = max(kotae, kari2);
	}

	printf("%lld", kotae);

	Would you please return 0;
}