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
	ll n, k;
	cin >>n >>k;
	
	ll s = n /k;
	ll ans = s * s * s;
	if(k%2==0){
		ll ss = n /(k/2);
		ss -= s;
		ans += ss * ss *ss;
	}
	cout << ans <<"\n";
	

	
	return 0;
}
