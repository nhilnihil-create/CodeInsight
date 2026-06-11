#include <bits/stdc++.h>

using namespace std;
 
#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

typedef int64_t ll; typedef vector<int> VI; typedef pair<ll,ll> pii;
const int MD = 1e9+7; typedef vector<ll> VL;

void dbg(){ cerr << "\n"; }  
template <typename T,typename ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }


int main()
{
	
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	VL a(n), b(n+1);
	rep(i, n) cin >>a[i];
	
	rep(i, n) b[i+1] = b[i] + a[i];
	//for(auto x :b) printf("%lld ",x); puts("");
	ll ans = 1LL<<60;
	rep2(i, 1, n-1){
		
		ll smb = b[i+1]/2;
		ll sma = (b[n] - b[i+1])/2;
		int ps1 = lower_bound(all(b), smb) - b.begin();
		int ps2 = lower_bound(all(b), sma+b[i+1]) - b.begin();
		rep2(x, max(0,ps1-5), min(ps1+5,i+1)) rep2(y, max(i,ps2-5), min(n,ps2+6)){				VL qs={b[x+1], b[i+1]-b[x+1], b[y+1]-b[i+1], b[n]-b[y+1]};
			if(qs[0]==0 || qs[1]==0 || qs[2]==0 || qs[3]==0 ) continue;
			ll mnsm = min<ll>({ qs[0], qs[1], qs[2], qs[3] });
			ll mxsm = max<ll>({ qs[0], qs[1], qs[2], qs[3] });
			//dbg("sm",x,i,y,mnsm,mxsm);
			ans = min<ll>(ans, mxsm - mnsm);
		}
	}
	cout << ans <<endl;
	return 0;
}
