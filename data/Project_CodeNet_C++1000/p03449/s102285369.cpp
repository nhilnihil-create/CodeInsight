#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;
	cin >> N;
	vector<vector<int>> A(2, vector<int>( N));
	int ans = 0;
	rep(i,N){
		cin >> A[0][i];
		ans += A[0][i];
	}
	rep(i,N) cin >> A[1][i];
	ans += A[1][N-1];
	int tmp = ans;
	for(int i = N -1; i >= 1; --i){
		tmp = tmp - A[0][i] + A[1][i-1];
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}












