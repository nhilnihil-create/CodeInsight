#include <bits/stdc++.h>


#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <class T, class ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}
typedef pair<ll, ll> pll;

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, k;
	cin >>n >>k;
	
	vector<pii> xy(n);
	rep(i, n) cin >>xy[i].first >>xy[i].second;
	
	VI ys(n);
	rep(i,n) ys[i] = xy[i].second;
	sort(all(ys));
	ys.erase(unique(all(ys)), ys.end());
	int yz=sz(ys);
	sort(all(xy));
	ll ans = 1LL<<62;
	VI adk(n);
	rep(y1, yz) rep2(y2, y1,yz){
		adk.clear();
		rep(i, n){
			if(ys[y1] > xy[i].second || xy[i].second > ys[y2]) continue;
			adk.push_back(xy[i].first);
			if(sz(adk) >=k){
				ll w=(1LL*ys[y2]-ys[y1]) * (adk.back() - adk[sz(adk) -k]);
				ans = min(ans, w);
			}
		}
	}

	cout << ans <<"\n";
	return 0;
}
