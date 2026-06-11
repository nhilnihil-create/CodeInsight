#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	int H, W, D;
	cin >> H >> W >> D;
	int A[310][310];
	rep(i,H){
		rep(j,W) cin >> A[i][j];
	}
	int Q;
	cin >> Q;
	vector<int> L(Q), R(Q);
	rep(i,Q) cin >> L[i] >> R[i];
	rep(i,Q) L[i]--, R[i]--;
	vector<P> C(H*W+1);
	rep(i,H){
		rep(j,W) C[A[i][j]-1]=P(i,j);
	}
	vector<vector<int>> sum(D);
	rep(i,D) sum[i].emplace_back(0);
	rep(i,D){
		for(int j=i; j+D<H*W; j+=D){
			int x=abs(C[j+D].first-C[j].first);
			int y=abs(C[j+D].second-C[j].second);
			sum[i].emplace_back(sum[i].back()+x+y);
		}
	}
	rep(i,Q){
		int d=L[i]%D;
		int l=L[i]/D, r=R[i]/D;
		cout << sum[d][r]-sum[d][l] << endl;
	}

	return 0;
}