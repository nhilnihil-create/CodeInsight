/************************************/
/* NoobM							*/
/* File Name : chaa.cpp				*/
/* Date : 13.07.2020 02:37:00 +06	*/
/************************************/

#include <bits/stdc++.h>

#define rr(i, b)    for (int i = 0; i < int(b); i++)
#define vi(n, a) vector <int> a(n); rr(i, n) cin >> a[i]
#define pvec(a) rr(i, a.size()) cout << a[i] << " "; cout << endl
#define bug(x) cout << #x << " " << x << endl
#define ll long long
#define vii vector <int>

using namespace std;

void solve() {
	int n;
	cin >> n;
	
	vi(n, a);
	
	sort(a.rbegin(), a.rend());
	
	ll alice = 0;
	ll bob = 0;
	
	for(int i = 0; i < n; i++) {
		if(i % 2 == 0) alice += a[i];
		else bob += a[i];
	}
	
	cout << alice - bob << endl;
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	
	int t = 1;
	//cin >> t;
	
	while (t--) {
		solve();
	}
    return 0;
}
