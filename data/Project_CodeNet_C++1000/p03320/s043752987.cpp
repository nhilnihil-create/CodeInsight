#pragma comment(linker, "/stack:200000000")

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define ll long long 
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
int k;
ll ans[1000000];
int toint(string s){
	reverse(all(s));
	int res = 0;
	for(int i = 0 ; i < sz(s) ; i++){
		res += (s[i] - '0');
		res *= 10;
	}
	res /= 10;
	return res;
}
int get(int n){
	int res = 0;
	while(n != 0)
		res += n % 10 , n /= 10ll;
	return res;
}

main(){
//    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//    freopen("t.out" , "w" , stdout);
	cin >> k ;
	ans[1] = 1;
	int add = 1;
	for(int i = 2 ; i <= k ; i++){
	   if((ans[i - 1] + add) * get(ans[i - 1] + add * 10ll) <= (ans[i - 1] + add * 10ll) * get(ans[i - 1] + add)){
	   		ans[i] = ans[i - 1] + add;
	   }
	   else
	   	add *= 10ll , ans[i] = ans[i - 1] + add;
	}
	for(int i = 1 ; i <= k ; i++)
		cout << ans[i] << '\n';



}