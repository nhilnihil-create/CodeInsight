#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }


int main()
{
	
	int n, m;
	cin >>n >>m;
	VL a(n), sm(n+1);
	rep(i, n) cin >>a[i];
	
	rep(i, n) (sm[i+1] = sm[i] + a[i] )%=m;
	map<ll, ll> mp;
	rep(i, n+1) mp[sm[i]]++;
	ll ans = 0;
	for(auto x: mp) if(x.second > 1){
		ans += (x.second *(x.second-1)) /2;
	}
	cout << ans <<"\n";
	return 0;
}
