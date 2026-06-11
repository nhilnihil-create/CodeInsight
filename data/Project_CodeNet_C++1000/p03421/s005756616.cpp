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
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

int main() {
	int A, B, N;
	cin >> N >> A >> B;
	if (N < A + B - 1 || (ll)A * B < N) {
		puts("-1");
		return 0;
	}
	vi ans;
	int now = N;
	rep(i, B) {
		int c = max(B-i-1, now - A);
		for (int k = c; k < now; ++k) {
			ans.pb(k);
		}
		now = c;
	}
	rep(i, N) {
		printf("%d%c", ans[i] + 1, i == N-1 ? '\n' : ' ');
	}
	return 0;
}