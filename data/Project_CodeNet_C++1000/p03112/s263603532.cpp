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
	int a, b, q;
	cin >>a >>b >>q;
	VL s(a+2), t(b+2), x(q);
	rep(i, a) cin >>s[i+1];
	rep(i, b) cin >>t[i+1];
	rep(i, q) cin >>x[i];
	s[0] = t[0] = -1LL<<55;
	s[a+1] = t[b+1] = 1LL<<55;

	auto zfc=[&](int i, VL& s, VL& t) ->ll{
		ll ans = 1LL<<60;
		int p1 = lower_bound(all(s), x[i]) - s.begin();
		int p2 = lower_bound(all(t), s[p1]) - t.begin();
		ll ds = abs(s[p1] - x[i]) + abs(t[p2]-s[p1]);
		ans = min(ans, ds);
		if(p2 > 0) ans = min(ans, abs(s[p1] - x[i]) + abs(t[p2-1]-s[p1]));
		if(p1 > 0){
			p1--;
			p2 = lower_bound(all(t), s[p1]) - t.begin();
			ans = min(ans, abs(s[p1] - x[i]) + abs(t[p2]-s[p1]));
			if(p2 > 0) ans = min(ans, abs(s[p1] - x[i]) + abs(t[p2-1]-s[p1]));
		}
		return ans;
	};


	rep(i, q){
		ll ans = min(zfc(i, s, t), zfc(i, t, s));
		cout << ans <<"\n";
	}
	return 0;
}
