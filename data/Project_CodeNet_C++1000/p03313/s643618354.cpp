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

const int MN = 1 << 18;

vi mx[MN];

int main() {
	int N; cin >> N;

	rep(i, 1 << N) {
		int x; cin >> x;
		mx[i].pb(x);
	}

	rep(i, N) {
		rep(j, 1 << N) {
			if (!((j >> i) & 1)) {
				int b = j | (1 << i);
				for (int x : mx[j]) {
					mx[b].pb(x);
				}
				sort(ALL(mx[b]));
				reverse(ALL(mx[b]));
				while (mx[b].size() > 2) {
					mx[b].pop_back();
				}
			}
		}
	}

	vi ans(1 << N);
	rep(i, 1 << N) {
		if (mx[i].size() >= 2) {
			ans[i] = mx[i][0] + mx[i][1];
		}
		if (i) {
			ans[i] = max(ans[i], ans[i-1]);
			cout << ans[i] << "\n";
		}
	}

	return 0;
}