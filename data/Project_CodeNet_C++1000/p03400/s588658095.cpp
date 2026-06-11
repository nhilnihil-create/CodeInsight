#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N, D, X;
	cin >> N >> D >> X;
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	int ans = N;
	rep(i,N){
		ans += (D-1)/A[i];
	}
	ans += X;
	cout << ans << endl;	
			
}










