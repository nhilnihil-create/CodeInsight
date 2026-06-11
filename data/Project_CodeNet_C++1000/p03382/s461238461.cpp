//#pragma comment(linker, "/stack:200000000")

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define ret(a) return cout<<a,0;
using namespace std;
typedef pair < ld , int > pii ;
typedef pair < long long  , long long > pll ;
const int N = 2e5 + 123 ;
int n , a[N];

main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	pii best = mp(1e9 + 123 , -1);
	ld o = 1.0 * a[n] / 2.0;
	for(int i = 1 ; i < n ;i++){
		best = min(best , { abs(o - a[i]) , i} );
	}
	cout << a[n] << ' ' << a[best.se] ;
}