
#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for (int i = a; i < b; i++)

const int mxn = 3e6;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n; cin >> n;
	int a[n];
	f(i,0,n) cin>>a[i];
	sort(a,a+n);
	bitset<mxn> dp;	
	dp[0] = 1;
	f(i,0,n) dp = dp | (dp<<a[i]);		
	int S = 0;
	f(i,0,n) S += a[i];
	f(j,S/2+(S&1),mxn) if (dp[j]) {
		cout << j << endl;
		break;
	}

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

