#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<ll,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; ll k;
	cin >>n >>k;
	VL a(n);
	rep(i, n) cin >>a[i];
	
	VI z(42);
	rep(i, 42){
		rep(j, n) z[i] += a[j]>>i & 1;
	}
	ll sp = 0;
	repr(i, 41, 0){
		if(z[i] < (n+1)/2 && sp + (1LL<<i) <= k) sp += 1LL<<i;
	}
	ll ans = 0;
	rep(i, n) ans += sp ^ a[i];
	cout << ans <<"\n";
	
	return 0;
}
