#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define pld pair <ld, ld>
#define ppll pair <pll, pll>
#define vll vector <ll>
#define vvll vector <vll>
#define vpll vector <pll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mll map <ll, ll>
#define fastmap gp_hash_table
#define cd complex <double>
#define vcd vector <cd>
#define PI 3.14159265358979
#pragma 03
using namespace std;
using namespace __gnu_pbds;
ll binpow(ll a, ll b){
	if (b == 0) return 1;
	ll x = binpow(a, b/2); x *= x;
	if (b % 2) return x * a; else return x;
}
int main(){
	ll m, k; cin >> m >> k;
	if (k >= binpow(2, m)){
		cout << -1 << endl; return 0;
	}
	else if (m == 0){
		if (k == 0) cout << "0 0" << endl;
		else cout << -1 << endl;
	}
	else if (m == 1){
		if (k == 0) cout << "0 0 1 1" << endl;
		else cout << -1 << endl;
	}
	else{
		for (ll i = 0; i<binpow(2, m); i++){
			if (i != k) cout << i << " ";
		}
		cout << k << " ";
		for (ll i = binpow(2, m) - 1; i>=0; i--){
			if (i != k) cout << i << " ";
		}
		cout << k << endl;
	}
}