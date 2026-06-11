
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = INTINF;
	int tmp;
	int h, w, d;
	cin >> h >> w >> d;
	int mp[h][w], x[h*w+1], y[h*w+1], rui[h*w+1];
	REP(i, h){
		REP(j, w){
			cin >> mp[i][j];
			x[mp[i][j]] = i;
			y[mp[i][j]] = j;
		}
	}
	REP(i, h*w+1){
		if(i-d<0) rui[i] = 0;
		else rui[i] = rui[i-d] + abs(x[i-d] - x[i]) + abs(y[i-d] - y[i]);
	}
	int q, l, r;
	cin >> q;
	REP(i,q){
		cin >> l >> r;
		cout << rui[r] - rui[l] << endl;
	}
}
