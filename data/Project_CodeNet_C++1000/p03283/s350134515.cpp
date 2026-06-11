#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<int> L(M), R(M);
	rep(i,M) cin >> L[i] >> R[i];
	vector<int> p(Q), q(Q);
	rep(i,Q) cin >> p[i] >> q[i];
	vector<vector<int>> T(N+1);
	rep(i,M) T[R[i]].emplace_back(L[i]);
	int num[510][510]={0};
	for(int i=1; i<=N; i++){
		for(int j=i; j<=N; j++){
			num[i][j]=num[i][j-1];
			rep(k,T[j].size()){
				if(T[j][k]>=i) num[i][j]++;
			}
		}
	}
	rep(i,Q) cout << num[p[i]][q[i]] << endl;

	return 0;
}