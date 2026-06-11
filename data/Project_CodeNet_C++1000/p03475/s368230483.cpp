#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
const int INF=1e9;

int main(){
	int N;
	cin >> N;
	vector<int> C(N-1), S(N-1), F(N-1);
	rep(i,N-1) cin >> C[i] >> S[i] >> F[i];
	vector<int> ans(N);
	ans[N-1]=0;
	rep(i,N-1){
		int time=0;
		for(int j=i; j<N-1; j++){
			int M=max(time,S[j]);
			time=(M+F[j]-1)/F[j]*F[j];			
			time+=C[j];			
		}
		ans[i]=time;
	}
	rep(i,N) cout << ans[i] << endl;

	return 0;
}