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

//当時の自分の方が天才っぽい
int D[100001];
int P[100001];
int to[100001], ne[100001], he[100001];
int sagasu(int A) {
	if (D[A]) return D[A];
	int ret = 1;
	for (int i = he[A]; i; i = ne[i]) {
		int u = to[i];
		int kari = sagasu(u) + 1;
		if (ret < kari) {
			ret = kari;
			P[A] = u;
		}
	}
	return 	D[A] = ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, M;
	cin >> N >> M;
	rep1(i, N + M - 1) {
		int a, b;
		cin >> a >> b;
		to[i] = a;
		ne[i] = he[b];
		he[b] = i;
	}

	rep1(i, N) {
		sagasu(i);
		co(P[i]);
	}

	Would you please return 0;
}