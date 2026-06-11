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
	int n, m;
	cin >>n >>m;
	vector<VL> x(n, VL(3));
	rep(i, n) cin >>x[i][0] >>x[i][1] >>x[i][2];
	
	ll ans = -1LL<<60;
	rep(i, 1<<3){
		VL smz(n);
		rep(k, n){
			ll sm = 0;
			rep(j, 3) sm += (i>>j &1)? x[k][j]: -x[k][j];
			smz[k] = sm;
		}
		sort(smz.rbegin(), smz.rend());
		ll w = accumulate(smz.begin(), smz.begin()+m, 0LL);
		ans = max(ans, w);
	}
	
	cout << ans <<"\n";
	return 0;
}
