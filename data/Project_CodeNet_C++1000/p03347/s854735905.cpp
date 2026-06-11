#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << #x << " :: " << x << endl
#define _ << " " <<
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for (int i=(a);i>=(b);--i)
using ll=long long;

const int mxN = 2e5+5;

int N, A[mxN];

void die() { cout << -1 << '\n'; exit(0); }

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N;
    FOR(i,1,N){
		cin >> A[i];
	}
	
	if (A[1] > 0) die();
	FOR(i,1,N-1){
		if (A[i+1]-A[i] > 1) die();
	}
	
	ll ans = 0;
	FOR(i,2,N){
		if (A[i]-A[i-1] == 1) ++ans;
		else ans += A[i];
	}
	
	cout << ans << '\n';
}
