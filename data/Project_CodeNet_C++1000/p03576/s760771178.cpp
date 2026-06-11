#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = 1e9+7;

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,K;
	cin >> N >> K;
	vector<ll> x(N),y(N);
	rep(i,N)cin >> x[i] >> y[i];
	ll ans = INF;
	rep(a,N)rep(b,N){
		if(a==b)continue;
		ll xl = min(x[a],x[b]);
		ll xr = max(x[a],x[b]);
		ll xlength = xr - xl;
		//[xl,xr]にある点の中からyを決める
		rep(c,N)rep(d,N){
			bool ok = 0;
			if(xl<=x[c]&&x[c]<=xr&&xl<=x[d]&&x[d]<=xr)ok = 1;
			if(!ok)continue;
			ll yt = max(y[c],y[d]);
			ll yb = min(y[c],y[d]);
			ll ylength = yt-yb;
			int cnt = 0;
			rep(e,N){
				//中に含まれるかどうか調べる
				if(xl<=x[e]&&x[e]<=xr&&yb<=y[e]&&y[e]<=yt)cnt++;
			}
			if(cnt>=K){
				ans = min(ans,xlength*ylength);
			}
		}
	}
	cout << ans << endl;
}