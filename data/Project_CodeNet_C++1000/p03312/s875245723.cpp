#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <class T, class ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	VL a(n), b(n+1);
	rep(i, n) cin >>a[i];
	
	rep(i, n) b[i+1] = b[i] + a[i];
	ll ans = 1LL<<55;;
	rep2(i,1, n-2){
		
		ll bf = b[i+1], af = b[n] - bf;
		int z1 = lower_bound(all(b), bf/2) - b.begin();
		int z2 = lower_bound(all(b), bf+af/2) - b.begin();
	
		rep2(j1, z1-2, z1+3) rep2(j2, z2-2, z2+3){
			if(j1 <0 || j1>=i) continue;
			if(j2 <i || j2 >=n-1) continue;
			ll mn = min({b[j1+1], b[i+1]-b[j1+1], b[j2+1]-b[i+1], b[n] -b[j2+1]});
			ll mx = max({b[j1+1], b[i+1]-b[j1+1], b[j2+1]-b[i+1], b[n] -b[j2+1]});
			ans = min(ans, mx - mn);
		}
	}
	cout << ans <<"\n";
	return 0;
}
