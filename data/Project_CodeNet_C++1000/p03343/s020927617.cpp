#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[2005], which[2005], sz[2005];
pi b[2005];

int main()
{
	IO_OP;
	
	int n, k, q, ans = INF;
	cin >> n >> k >> q;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		b[i].F = a[i], b[i].S = i;
	sort(b, b+n);
	for(int i=0;i<n;i++) {
		int y = b[i].F, x = 0;
		for(int i=0;i<n;i++)
			sz[i] = which[i] = 0;
		for(int i=0;i<n;i++) {
			if(a[i] >= y) {
				which[i] = x;
				sz[x]++;
			} else {
				x++;
			}
		}
		int mx = -1, l=0;
		for(int j=i;j<n && l<q;j++) {
			int yi = b[j].S;
			int bl = which[yi];
			if(sz[bl] >= k) {
				sz[bl]--;
				l++;
//				cout << "del " << b[j].F << endl;
				mx = max(mx, b[j].F);
			}
		}
		if(l != q || mx == -1) continue;
		ans = min(ans, mx - y);
//		cout << mx << " - " << y << " = " << mx - y << endl;
	}
	cout << ans << endl;
}

