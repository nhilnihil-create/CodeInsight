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

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }
	return *ci++;
}
inline int getint() {
	int A = 0;
	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}

pair<int, int> E[400001];
int ne[400001], H[100001], D[100001];
bool dame, vi[100001];
void dfs(int p, int mae, int d) {
	D[p] = d;
	vi[p] = true;
	for (int i = H[p]; i; i = ne[i]) {
		int n = E[i].first;
		if (n != mae) {
			if (vi[n]) {
				if (D[n] != d + E[i].second) dame = true;
			}
			else dfs(n, p, d + E[i].second);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N = getint(), M = getint();
	rep(i, M) {
		int l = getint(), r = getint(), d = getint();
		E[i + i + 1] = mp(r, d);
		ne[i + i + 1] = H[l];
		H[l] = i + i + 1;
		E[i + i + 2] = mp(l, -d);
		ne[i + i + 2] = H[r];
		H[r] = i + i + 2;
	}

	rep1(i, N) {
		if (!vi[i]) {
			dfs(i, 0, 0);
		}
	}

	if (dame) co("No");
	else co("Yes");

	Would you please return 0;
}