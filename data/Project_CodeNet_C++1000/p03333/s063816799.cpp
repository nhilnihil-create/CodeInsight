
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f(i,a,b) for (int i = a; i < b; i++)
#define Max(a,b) a=max(a,b)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n; cin>>n;
	n++;
	int l[n],r[n];
	l[0]=r[0]=0;
	f(i,1,n) cin>>l[i]>>r[i];
	sort(l,l+n,greater<int>());
	sort(r,r+n);	
	ll pl[n], pr[n];
	f(i,0,n) pl[i] = (i?pl[i-1]:0)+l[i];
	f(i,0,n) pr[i] = (i?pr[i-1]:0)+r[i];
	ll ans = 0;
	f(k,0,n/2)
		Max(ans,pl[k]-pr[k]);	
	cout << 2LL*ans << endl;



#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

