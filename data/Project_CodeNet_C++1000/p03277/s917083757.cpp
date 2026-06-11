#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define rep(pos, len) for(int pos=0;pos<len;pos++)
#define repp(pos, len) for(int pos=1;pos<=len;pos++)

#define INF 987654321
#define IINF 2987654321987654321
#define MOD 1000000007

struct SegmentTree {
	int n;
	vector<ll> st;

	void init(int sz) {
		n = 1;
		while(n < sz) n <<= 1;
		st.assign(2*n, 0LL);
	}

	void reset() {
		fill(st.begin(), st.end(), 0LL);
	}

	void update(ll p, ll val) {
		p += n-1;
		st[p] += val;
		for(p >>= 1; p; p >>= 1)
			st[p] = st[2*p] + st[2*p+1];
	}

	ll rangeSum(int l, int r) {
		ll sum = 0;
		for(l += n-1, r += n-1; l <= r; l >>= 1, r >>= 1) {
			if(l&1) sum += st[l++];
			if(!(r&1)) sum += st[r--];
		}
		return sum;
	}
} tree;


const int MAXN = 1e5 + 50;
ll n, m, a[MAXN];
void readInput() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	tree.init(2*n+1);
	m = n*(n+1)/2;
}

bool check(ll x) {
	tree.reset();
	ll sum = n+1, cnt = 0;
	tree.update(sum, 1);
	for(int i = 1; i <= n; i++) {
		sum += (a[i] >= x) ? 1 : -1;
		cnt += tree.rangeSum(1, sum);
		tree.update(sum, 1);
	}
	return cnt >= (m - (m/2+1) + 1);
}

void solve() {
	ll low = 1, high = 1000000000LL, res = -1;
	while(low <= high) {
		ll mid = (low + high) / 2;
		if(check(mid)) {
			res = mid;
			low = mid+1;
		} else {
			high = mid-1;
		}
	}
	printf("%lld\n", res);
}

int main() {
	readInput();
	solve();
}	