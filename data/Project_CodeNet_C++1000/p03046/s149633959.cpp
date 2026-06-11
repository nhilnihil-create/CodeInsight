#include <bits/stdc++.h>
 
#ifndef ONLINE_JUDGE
	#define W(x, y) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << y;
#else
	#define W(x, y)
#endif
 
 
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pi acosl(-1)
#define ld long double
#define prime (1000000000 + 7)
#define INF 1000000000
 
using namespace std;



int main(){
	#ifdef ONLINE_JUDGE
		ios::sync_with_stdio(false);
		cin.tie(0); cout.tie(0);
	#endif

	ll n, k;
	cin >> n >> k;
	if(k >= (1 << n) || (n == 1 && k == 1)) {
		cout << -1 << "\n";
	} else if(n == 1 && k == 0) {
		cout << "0 0 1 1\n";
	} else{
		cout << k << " ";
		for(int i = 0; i < (1 << n); ++i){
			if(i != k){
				cout << i << " ";
			}
		}
		cout << k << " ";
		for(int i = (1 << n) - 1; i >= 0; --i){
			if(i != k){
				cout << i << " ";
			}
		}
		cout << "\n";
	}


	return 0;
}