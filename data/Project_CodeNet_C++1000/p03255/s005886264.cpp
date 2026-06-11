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

const int MN = 200010;
const ll INF = 1e18;

int N;
ll X;
int x[MN];
ll s[MN];

int main() {
	cin >> N >> X;

	rep(i, N) {
		cin >> x[i];
		s[i+1] = s[i] + x[i];
	}

	ll ret = LLONG_MAX;

	for (int num = 1; num <= N; ++num) {
		ll t = X * (num + N);
		int u = 0;
		bool sf = 1;

		for (int i = N; i >= 0; i -= num) {
			++u;

			if (u == 1) {
				t += (s[i] - s[i - num]) * 5;
			} else {
				ll ad = s[i] - s[max(0, i - num)];
				t += ad * (u * 2 + 1);
			}
			if (t > INF) {
				sf = 0;
				break;
			}
		}

		if (sf) {
			ret = min(ret, t);
		}
	}

	cout << ret << endl;

	return 0;
}