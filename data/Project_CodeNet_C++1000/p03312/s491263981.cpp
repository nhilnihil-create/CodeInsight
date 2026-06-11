#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e18 + 9;
 
int lx[N], lm[N], rx[N], rm[N], a[N];

signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;	cin >> n;
	lx[0] = 0, lm[0] = inf;
	int l = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	lx[1] = a[1];	lm[1] = 0;
	int s1 = a[1], s2 = 0;
	for(int i = 2; i <= n; i++){
		s1 += a[i];
		while(true){
			int cur = abs((s1 - s2) - s2);
			int nxt = abs((s1 - s2 - a[l+1]) - (s2 + a[l+1]));
			if(nxt > cur)
				break;
			l++;	s2 += a[l];
		}
		lx[i] = max(s2, s1 - s2);
		lm[i] = min(s2, s1 - s2);
	}
	rx[n] = a[n];	rm[n] = inf;
	l = n+1;
	s1 = a[n];	s2 = 0;
	for(int i = n-1; i >= 1; i--){
		s1 += a[i];
		while(true){
			int cur = abs((s1 - s2) - s2);
			int nxt = abs((s1 - s2 - a[l-1]) - (s2 + a[l-1]));
			if(nxt > cur)
				break;
			l--;	s2 += a[l];
		}
		rx[i] = max(s2, s1 - s2);
		rm[i] = min(s2, s1 - s2);
	}
	int mx = 0, mi = inf, ans = inf;
	for(int i = 2; i+1 < n; i++){
		mx = max(lx[i], rx[i+1]);
		mi = min(lm[i], rm[i+1]);
		ans = min(ans, mx - mi);
	}
	cout << ans;
	return 0;
}