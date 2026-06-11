#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,K;
	cin >> N >> K;
	long long ans = 1LL<<62;
	vector<ll> x(N),y(N);
	rep(i,N)cin >> x[i] >> y[i];
	rep(a,N)rep(b,N)rep(c,N)rep(d,N){
		ll left = min(x[a],x[b]);
		ll right= max(x[a],x[b]);
		ll up = max(y[c],y[d]);
		ll down = min(y[c],y[d]);
		int cnt = 0;
		rep(e,N)if(left<=x[e] && x[e] <= right && down <= y[e] && y[e] <= up)cnt++;
		if(cnt>=K)ans = min(ans,abs(left-right)*abs(up-down));
	}
	cout << ans << endl;
}