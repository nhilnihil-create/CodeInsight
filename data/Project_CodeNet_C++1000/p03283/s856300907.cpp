#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000 //14

int main(){
	ll n, m, q, l, r; cin >> n >> m >> q;
	vector<vector<ll>> ansl(n,vector<ll>(n,0));
	REP(i,m){
		cin >> l >> r;l--;r--;
		ansl[l][r]++;
	}
	FOR(i,1,n-1) ansl[i][0]=ansl[i-1][0]+ansl[i][0];
	FOR(i,1,n-1) ansl[0][i]=ansl[0][i-1]+ansl[0][i];
	FOR(i,1,n-1)FOR(j,1,n-1) ansl[i][j]=ansl[i-1][j]+ansl[i][j-1]-ansl[i-1][j-1]+ansl[i][j];
	REP(i,q){
		cin >> l >> r;l--;r--;
		if (l==0) cout << ansl[r][r] << endl;
		else cout << ansl[r][r]-ansl[l-1][r]-ansl[r][l-1]+ansl[l-1][l-1] << endl;
	}
}