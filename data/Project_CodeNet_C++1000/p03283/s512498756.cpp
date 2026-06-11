#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).rbegin(),(a).rend())
#define ll long long
#define pb(a) push_back(a)

#define PRINTV(v) {for(ll deB=0; deB<(v).size(); deB++){cout << (v)[deB] << " ";}cout << endl;}

int main(){
	
	
	ll N, M, Q;
	cin >> N >> M >> Q;
	vector<ll> L(M), R(M);
	REP(i,M) cin >> L[i] >> R[i];
	vector<ll> p(Q), q(Q);
	REP(i,Q) cin >> p[i] >> q[i];

	vector<vector < ll > > LR(N+1, vector<ll>(N+1, 0));
	vector<vector < ll > > cumsum(N+2, vector<ll>(N+2, 0));

	for(int i=0; i<M; i++){
		LR[L[i]][R[i]] ++;
	}
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++){
			cumsum[i][j] = -cumsum[i-1][j-1] + cumsum[i][j-1] + cumsum[i-1][j] + LR[i][j];
		}
	}

	for(int i=0; i<Q; i++){
		cout << cumsum[q[i]][q[i]] - cumsum[p[i]-1][q[i]] - cumsum[q[i]][p[i]-1] + cumsum[p[i]-1][p[i]-1] << endl;
	}
	
	return 0;

abnormal:
	cout << "No" << endl;
	return 0;
}