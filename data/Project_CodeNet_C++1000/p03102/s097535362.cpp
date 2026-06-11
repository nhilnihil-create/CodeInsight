#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;


int main(){
	int N,M;
	int C;
	cin >> N >> M >> C;
	vector<int> B(M);
	rep(i,M)cin >> B[i];
	int ans = 0;
	rep(i,N){
		ll S = 0;
		rep(j,M){
			int A; cin >> A;
			S += A*B[j];
		}
		S += C;
		if(S>0)ans++;
	}

	cout << ans << endl;

	return 0;
}