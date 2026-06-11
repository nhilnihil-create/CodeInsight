#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N, M, X;
	cin >> N >> M >> X;
	vector<int> A(M);
    rep(i,M) cin >> A[i];
	int tmp = 0;
	rep(i,M){
		if(A[i]	> X) break;
		tmp++;
		
	}
	int ans = M;
	ans = min(tmp, M - tmp);
	cout << ans << endl;
	return 0;

}










