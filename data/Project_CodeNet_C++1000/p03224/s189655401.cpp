#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	if(n == 2){
		cout << "No" << endl;
		return 0;
	}

	ll a = 1;
	for(; a <= n; a++){
		if(a * (a-1) / 2 > n){
			cout << "No" << endl;
			return 0;
		}
		if(a * (a-1) / 2 == n) break;
	}

	ll g[a+1][a];
	rep(i, a+1) rep(j, a) g[i][j] = 0;

	ll ind[a+1];
	rep(i, a+1) ind[i] = 0;

	ll l = 1;
	for(ll i = 1; i < a; i++){
		for(ll j = i+1; j <= a; j++){
			g[i][ind[i]] = l;
			g[j][ind[j]] = l;
			ind[i]++;
			ind[j]++;
			l++;
		}
	}

	cout << "Yes" << endl;
	cout << a << endl;
	rep(i, a){
		cout << a-1;
		rep(j, a-1){
			cout << " " << g[i+1][j];
		}
		cout << endl;
	}
}
