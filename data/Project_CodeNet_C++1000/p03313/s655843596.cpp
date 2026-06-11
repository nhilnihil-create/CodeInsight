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

int BIT[1000000];
void add(int A, int B) {
	while (A <= 1000000) {
		BIT[A] = max(BIT[A], B);
		A += A & -A;
	}
}

int query(int A) {
	int kotae = 0;
	while (A > 0) {
		kotae = max(kotae, BIT[A]);
		A -= A & -A;
	}
	return kotae;
}

int N;
int B[1000000];
pair<pair<int, int>, pair<int, int>> memo[1000000];
pair<pair<int, int>, pair<int, int>> keisan(int A) {
	if (memo[A].first.first != 0) return memo[A];
	if (A == 0) memo[0] = mp(mp(B[0], 0), mp(0, 0));
	else {
		set<pair<int, int>> V;
		V.insert(mp(B[A], A));
		rep(i, N) {
			if (A >> i & 1) {
				auto p = keisan(A - (1 << i));
				V.insert(p.first);
				V.insert(p.second);
			}
		}
		memo[A] = mp(*(--V.end()), *(--(--V.end())));
	}
	return memo[A];
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	cin >> N;
	rep(i, 1 << N) cin >> B[i];

	rep1(i, (1 << N) - 1) {
		auto p = keisan(i);
		add(i, p.first.first + p.second.first);
		co(query(i));
	}

	Would you please return 0;
}