#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i,N) cin >> A[i];
	int ans=A[0];
	rep(i,N-1) ans=gcd(ans,A[i+1]);
	cout << ans << endl;

	return 0;
}