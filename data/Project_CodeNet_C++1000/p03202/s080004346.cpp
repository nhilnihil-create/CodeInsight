#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl

const int MN = 200010;

int N;
int A[MN];

bool ok(int x) {
	set<pii> S;

	int cl = A[0];

	map<int, int> M;
	for (int i = 1; i < N; ++i) {
		if (A[i] <= cl) {
			while (!M.empty()) {
				auto it = M.end(); --it;
				if (it->fi >= A[i]) {
					M.erase(it);
				} else {
					break;
				}
			}

			int p = A[i] - 1;
			++M[p];

			while (M[p] >= x) {
				M.erase(p);
				--p;
				if (p < 0) {
					return false;
				}
				++M[p];
			}
		}
		cl = A[i];
	}
	return true;
}

int main() {
	cin >> N;
	rep(i, N) {
		cin >> A[i];
	}

	bool mon = 1;
	rep(i, N-1) if (A[i] <= A[i-1]) {
		mon = 0;
	}

	if (mon) {
		puts("1");
		return 0;
	}

	int lo = 1, hi = N;

	while (hi - lo > 1) {
		int m = (lo + hi) / 2;
		if (ok(m)) {
			hi = m;
		} else {
			lo = m;
		}
	}

	cout << hi << endl;
	return 0;
}