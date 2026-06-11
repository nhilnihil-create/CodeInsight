// Author : Harshdeep Sharma , IIT Indore
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
// #define MOD  998244353
#define ll long long
const double PI = atan(1.0) * 4;
// const ll INF = (int)1e9 ;
const int di[4] = { -1, 0, 1, 0} ;
const int dj[4] = {0, -1, 0, 1} ;
const ll INF = (ll)2e18 + 50;
const int maximum  = numeric_limits<int>::min();
const int minimum  = numeric_limits<int>::max();

// function to calculate any numbered power of some number without modulo
ll power(ll a , ll e) {
	ll res = 1LL ;
	while (e > 0) {
		if (e % 2 == 1) res = res * a;
		a =  a * a  ;
		e /= 2 ;
	}
	return res ;
}
// function to check whether a bracketed sequence is balanced or not
bool isBalanced(const string &exp) {
	// Initialising Variables
	bool flag = true;
	int count = 0;

	// Traversing the Expression
	for (int i = 0; i < exp.length(); i++) {

		if (exp[i] == '(') {
			count++;
		}
		else {
			count--;
		}
		if (count < 0) {
			flag = false;
			break;
		}
	}
	if (count != 0) {
		flag = false;
	}

	return flag;
}
// function to sort by second in a set of pairs
bool sortbysec(const pair<pair<int, int>, int> &a,
               const pair<pair<int, int>, int> &b) {
	return (a.second < b.second);
}

void uniformly_distribute_k_numbers_in_a_square_grid(int n , int k ) {
	int p = 0 , q = 0 ;
	vector<vector<int>> a(n, vector<int>(n)) ;
	for (int i = 1 ; i <= k ; ++i ) {
		a[p][q] = 1 ;
		p = p + 1 ;
		q = (q + 1) % n ;
		if (p == n) {
			p = 0  ;
			q = (q + 1) % n ;

		}
	}
}



// main funtion
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int t ;
	// cin >> t ;
	// while (t--) {
	int n , m ;
	cin >> n >> m  ;
	ll ans = 0 ;
	ll rem = m ;
	// vector<int> b(n) ;
	// vector<ll> a(n) ;
	vector<pair<ll, ll>> p(n) ;
	for (int  i = 0  ; i < n ; i++) {
		cin >> p[i].first >> p[i].second ;
	}
	sort(p.begin() , p.end()) ;
	// for (int i = 0 ; i < n ; i++) {
	// 	cout << p[i].first << " " << p[i].second << "\n";
	// }
	for (int i = 0 ; i < n ; i++) {
		if (rem < p[i].second) {
			ans += p[i].first * rem ;
			break ;
		} else {
			rem -= p[i].second ;
			ans += p[i].first * p[i].second  ;
		}
	}
	cout << ans << "\n";

	// ll a , b ;
	// cin >> a >> b ;
	// // we have to find the Xor of a , a+1 , a+2 , .... , b .
	// ll cnt(60) ;
	// for(int i = 0 ; i < 60 ; i++){

	// }











	// }







	return 0 ;
}
