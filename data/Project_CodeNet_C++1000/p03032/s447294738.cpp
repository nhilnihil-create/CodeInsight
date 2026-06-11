#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, k;
	cin >>n >>k;
	VI v(n), gt;
	rep(i, n) cin >>v[i];
	ll ans = 0;
	rep(l, k+1) rep(r, k-l+1){
		if(l+r > n) continue;
		gt.clear();
		rep(i, l) gt.push_back(v[i]);
		rep(i, r) gt.push_back(v[n-1-i]);
		sort(all(gt));
		ll sm = accumulate(all(gt), 0LL);
		rep(i, min(sz(gt), k-l-r)){
			if(gt[i] < 0) sm -=gt[i];
		}
		//for(auto x :gt) cerr<<x<<" "; dbg("lr",l,r,sm);
		ans = max(ans, sm);
	}
	cout <<ans <<"\n";
	return 0;
}
