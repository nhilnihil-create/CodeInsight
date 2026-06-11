#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

/*
void print_vec(vector<ll>& v){
	REP(i, v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
	return;
}
*/

ll solve(ll N, ll C, vector<ll>& x, vector<ll>& v){
	vector<ll> clock(N), anti(N), v_cum(N, 0);
	v_cum[0] = v[0];
	REP(i, N-1){
		v_cum[i+1] = v_cum[i] + v[i+1]; 
	}

	REP(i, N){
		clock[i] = v_cum[i] - x[i];
	}

	ll v_rev_cum = 0;
	REP(i, N){
		v_rev_cum += v[N-1-i];
		anti[i] = v_rev_cum - (C - x[N-1-i]);
	}

	vector<ll> anti_max(N);
	anti_max[0] = anti[0];
	for(int i=1;i<N;i++){
		anti_max[i] = max(anti[i], anti_max[i-1]);
	}

	ll res = 0;
	REP(i, N){
		res = max(res, clock[i]);
	}
	REP(i, N-1){
		res = max(res, v_cum[i] - 2 * x[i] + anti_max[N-2-i]);
	}
	return res;
}

int main(){
	ll N, C;
	cin >> N >> C;
	vector<ll> x(N), v(N);
	REP(i, N) cin >> x[i] >> v[i];
	vector<ll> x_rev(N), v_rev(N);
	REP(i, N){
		x_rev[i] = C - x[N-1-i];
		v_rev[i] = v[N-1-i];
	}
	cout << max(solve(N, C, x, v), solve(N, C, x_rev, v_rev)) << endl;
    return 0;
}