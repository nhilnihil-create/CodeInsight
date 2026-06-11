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
	int LR[2002] = {};
	rep1(i, N) A[i] = ((ll)getint() << 16) + i;

	priority_queue<int> q;
	priority_queue<int, vector<int>, greater<int>> q2[1001];
	vector<int> qv[1001];
	int q3[2002] = {};
	int kotae = 1e9;
	int saishou = 2e9;
	sort(A + 1, A + N + 1);
	const int m = (1 << 16) - 1;
	int qn = 1;

	int num[1002] = {};
	int qflg[1002] = {};
	for (int i = N; i >= 1; i--) {
		int a = A[i] >> 16;
		int k = A[i] & m;

		int l = !LR[k - 1] ? k : LR[k - 1];
		int r = !LR[k + 1] ? k : LR[k + 1];
		LR[l] = r;
		LR[r] = l;

		if (l == r) q3[l] = qn++;
		int kosuu = min(K - 1, k - l);
		int kosuu2 = min(K - 1, r - k);
		if (k + k < l + r) {
			swap(q3[l], q3[k + 1]);
			swap(kosuu, kosuu2);
		}
		num[q3[l]] = kosuu + kosuu2 + 1;
		if (num[q3[l]] >= K && !qflg[q3[l]]) qflg[q3[l]] = 1;
	}

	rep1(i, N) LR[i] = 0;
	rep1(i, N) q3[i] = 0;
	qn = 1;

	for (int i = N; i >= 1; i--) {
		int a = A[i] >> 16;
		int k = A[i] & m;

		int l = !LR[k - 1] ? k : LR[k - 1];
		int r = !LR[k + 1] ? k : LR[k + 1];
		LR[l] = r;
		LR[r] = l;

		if (l == r) q3[l] = qn++;
		int kosuu = min(K - 1, k - l);
		int kosuu2 = min(K - 1, r - k);
		if (k + k < l + r) {
			swap(q3[l], q3[k + 1]);
			swap(kosuu, kosuu2);
		}

		if (qflg[q3[l]]) {
			auto L = q2 + q3[l];
			if (qflg[q3[k + 1]]) {
				auto R = q2 + q3[k + 1];
				rep(j, kosuu2) {
					(*L).push((*R).top());
					(*R).pop();
					if (kosuu == K - 1) {
						q.push((*L).top());
						(*L).pop();
					}
					else kosuu++;
				}
			}
			else {
				auto R = qv + q3[k + 1];
				rep(j, kosuu2) {
					(*L).push((*R)[j]);
					if (kosuu == K - 1) {
						q.push((*L).top());
						(*L).pop();
					}
					else kosuu++;
				}
			}
			(*L).push(a);
			if (kosuu == K - 1) {
				q.push((*L).top());
				(*L).pop();
			}
			while (q.size() >= Q) {
				int tmp = q.top();
				chmin(saishou, tmp);
				q.pop();
			}
		}
		else {
			auto L = qv + q3[l];
			auto R = qv + q3[k + 1];
			rep(j, kosuu2) (*L).pb((*R)[j]);
			(*L).pb(a);
		}
		chmin(kotae, saishou - a);
	}

	printf("%d", kotae);

	Would you please return 0;
}