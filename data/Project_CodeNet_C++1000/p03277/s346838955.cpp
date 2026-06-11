#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[100005], b[100005], p[100005], bit[200005];

int lowbit(int x) {
	return x & -x;
}

int qry(int i) {
	int ans = 0;
	while(i) {
		ans += bit[i];
		i -= lowbit(i);
	}
	return ans;
}

void add(int i, int x) {
	while(i < 200005) {
		bit[i] += x;
		i += lowbit(i);
	}
}

int ct(int k, int n) {
	for(int i=0;i<n;i++) 
		if(a[i] >= k)
			p[i+1] = 1;
		else
			p[i+1] = -1;
	p[0] = 0;
	for(int i=1;i<=n;i++)
		p[i] += p[i-1];
	//for(int i=0;i<=n;i++) cerr << "p[" << i << "]=" << p[i] << endl;
	for(int i=0;i<=n;i++)
		p[i] += n + 1;
	memset(bit, 0, sizeof(bit));
	int ans = 0;
	for(int i=0;i<=n;i++) {
		ans += qry(p[i]);
		add(p[i], 1);
	}
	//cerr << k << ' ' << ans << endl;
	return ans;
}

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		b[i] = a[i];
	sort(b, b+n);
	int l = 0, r = n-1;
	int v = n*(n+1) / 2;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ct(b[m], n) > (v-1) / 2) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << b[r] << endl;
}

