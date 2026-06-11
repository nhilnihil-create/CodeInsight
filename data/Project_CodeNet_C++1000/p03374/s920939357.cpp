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
typedef pair < int , int > pii ;
typedef pair < long long  , long long > pll ;
const int N = 2e5 + 123 ;
int n , c , x[N] , v[N] , dpc[N] , dpcc[N];
int dp[N] , ans = 0;
#define distc asfadfd
int distc(int x1 , int x2){
	return (x2 - x1 + c) % c;
}

main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> n >> c;
	for(int i = 1 ; i <= n ; i++)
		cin >> x[i] >> v[i];
	for(int i = 1 ; i <= n ; i++){
		dpc[i] = dpc[i - 1] + v[i] - distc(x[i - 1] , x[i]);
		ans = max(ans , dpc[i]);
	}
	multiset < int > st;
	for(int i = n ; i >= 1 ; i--){
		dpcc[i] = dpcc[i + 1] + v[i]  - distc(x[i] , x[i + 1]);
		ans = max(ans , dpcc[i]);
		st.insert(dpcc[i]);
	}
	st.insert(0);
	for(int i = 1 ; i <= n ; i++){
		st.erase(st.find(dpcc[i]));
		ans = max(ans , dpc[i] - x[i] + (int)(*st.rbegin()));
	}
	for(int i = n ; i >= 1 ; i--){
	 	st.insert(dpc[i]);
	}
	for(int i = n ; i >= 1 ; i--){
		st.erase(st.find(dpc[i]));		
		ans = max(ans , dpcc[i] - (c - x[i]) + (int)(*st.rbegin()) );
	}
	cout << ans;
	

}