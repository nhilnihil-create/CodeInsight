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

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	fread_unlocked(cn, 1, cm, stdin);
	int N = getint(), K = getint(), Q = getint();
	ll A[2002];
	int LR[2002];
	rep1(i, N) A[i] = ((ll)getint() << 16) + i;
	rep(i, N + 2) LR[i] = -1;

	priority_queue<int> q;
	priority_queue<int, vector<int>, greater<int>> q2[2002];
	int q3[2002];
	rep1(i, N) q3[i] = i;
	int kotae = 1e9;
	int saishou = 2e9;
	sort(A + 1, A + N + 1);
	const int m = (1 << 16) - 1;

	for (int i = N; i >= 1; i--) {
		int a = A[i] >> 16;
		int k = A[i] & m;

		int l = (LR[k - 1] == -1) ? k : LR[k - 1];
		int r = (LR[k + 1] == -1) ? k : LR[k + 1];
		LR[l] = r;
		LR[r] = l;

		if (k + k < l + r) swap(q3[l], q3[k + 1]);

		auto L = q2 + q3[l];
		auto R = q2 + q3[k + 1];

		while ((*R).size()) {
			int tmp = (*R).top();
			(*L).push(tmp);
			(*R).pop();
		}
		(*L).push(a);
		while ((*L).size() >= K) {
			int tmp = (*L).top();
			q.push(tmp);
			(*L).pop();
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