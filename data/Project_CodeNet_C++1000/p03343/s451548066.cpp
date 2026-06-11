#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<queue>
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
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

const int cm = 1 << 15;
char cn[cm], * ci = cn, ct;
inline int getint() {
	int A = 0;
	while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}

const int PN = 12;
const int KM = 1 << (PN - 1);
ll dat[1 << PN];

ll check(int L, int R, int A, int l, int r) {
	if (L <= l && r <= R) return dat[A];
	if (r <= L || R <= l) return 1ll << 60;
	return min(check(L, R, A * 2, l, (l + r) >> 1), check(L, R, A * 2 + 1, (l + r) >> 1, r));
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	fread_unlocked(cn, 1, cm, stdin);
	int N = getint(), K = getint(), Q = getint();
	ll A[2002];
	int LR[2002] = {};
	rep1(i, N) {
		A[i] = ((ll)getint() << 11) + i;
		dat[KM + i] = A[i];
	}
	for (int i = KM - 1; i > 0; i--) {
		dat[i] = min(dat[i * 2], dat[i * 2 + 1]);
	}

	priority_queue<int> q;
	int kotae = 1e9;
	int saishou = 2e9;
	sort(A + 1, A + N + 1);
	const int m = (1 << 11) - 1;

	for (int i = N; i >= 1; i--) {
		int a = A[i] >> 11;
		int k = A[i] & m;

		int l = !LR[k - 1] ? k : LR[k - 1];
		int r = !LR[k + 1] ? k : LR[k + 1];
		LR[l] = r;
		LR[r] = l;

		int kosuu = min(K - 1, r - k) + min(K - 1, k - l) + 1;
		int abureta = max(0, kosuu - K + 1);

		rep(i, abureta) {
			ll tmp = check(l, r + 1, 1, 0, KM);
			q.push(tmp >> 11);
			int k = 31 - __builtin_clz(tmp & m);
			int C = (tmp & m) + KM;
			dat[C] = 1ll << 60;
			rep(j, k) {
				ll tmp2 = min(dat[C], dat[C ^ 1]);
				dat[(C >>= 1)] = tmp2;
			}
		}

		while (q.size() >= Q) {
			int tmp = q.top();
			chmin(saishou, tmp);
			q.pop();
		}
		chmin(kotae, saishou - a);
	}

	printf("%d", kotae);

	Would you please return 0;
}