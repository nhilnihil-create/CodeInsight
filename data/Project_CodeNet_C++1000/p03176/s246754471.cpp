#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int bit[N];

void add(int pos, int val) {
	for(;pos < N;pos+=pos&-pos)
		bit[pos] = max(bit[pos], val);
}

int qry(int pos) {
	int ret = 0;
	for(;pos;pos-=pos&-pos)
		ret = max(ret, bit[pos]);
	return ret;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	vi h(n), a(n);
	for(int i = 0; i < n; i++) cin >> h[i];
	for(int i = 0; i < n; i++) cin >> a[i];
	int mx = 0;
	for(int i = 0; i < n; i++) {
		int dp = a[i] + qry(h[i]);
		add(h[i], dp);		
		mx = max(mx, dp);
	}
	cout << mx << endl;
}

