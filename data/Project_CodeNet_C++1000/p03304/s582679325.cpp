#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653

int main(){
	double n, m, d; cin >> n >> m >> d;
	if (n==1 && d==0) cout << setprecision(10) << (double)(m-1) << endl;
	else if (d==0) cout << setprecision(10) << (double)((n-d)*(m-1))/(n*n) << endl;
	else cout << setprecision(10) << (double)(2*(n-d)*(m-1))/(n*n) << endl;
}