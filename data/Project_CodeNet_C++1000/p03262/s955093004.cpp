#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	int N, X;
	cin >> N >> X;
	vector<int> x(N), d(N);
	rep(i,N) cin >> x[i];
	rep(i,N) d[i]=abs(X-x[i]);
	int ans=d[0];
	rep(i,N-1) ans=__gcd(ans,d[i+1]);
	cout << ans << endl;

	return 0;
}