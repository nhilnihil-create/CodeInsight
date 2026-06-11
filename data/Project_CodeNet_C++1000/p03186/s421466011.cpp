/*
Owner: dxxrk
Problem: Poisonous Cookies 
Date: 22/11/2019
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 9;
const int SM = 1e3 + 8;
const int logN = 20, BL = 400;
const double EPS = 3e-16;

int main(){
//	freopen("ex.in", "r", stdin);
//	freopen("ex.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int a, b, c; cin >> a >> b >> c;
	
	if(a + b >= c) return cout << b + c, 0;
	
	int ans = 0;
	while(c){
		ans++;
		c--;
		if(!a && !b) break;
		if(a) a--;
		else b--, ans++;
	}
	cout << ans;
	return 0;
}

