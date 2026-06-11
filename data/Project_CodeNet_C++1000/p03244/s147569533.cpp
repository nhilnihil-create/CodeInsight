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
	int n;
	cin >>n;
	map<int, int> gs, ks;
	rep(i, n){
		int v; cin >>v;
		if(i%2) ks[v]++;
		else gs[v]++;
	}
	
	vector<pii> gps, kps;
	for(auto x: gs) gps.emplace_back(x.second, x.first);
	for(auto x: ks) kps.emplace_back(x.second, x.first);
	
	sort(gps.rbegin(), gps.rend());
	sort(kps.rbegin(), kps.rend());
	int ans = 1<<28;
	if(sz(gps)==1 && sz(kps) ==1 && gps[0].second == kps[0].second){
		cout << n/2 <<"\n"; return 0;
	}
	if(gps[0].second != kps[0].second) ans = n - gps[0].first - kps[0].first;
	else{
		ans = n - gps[0].first - kps[1].first;
		ans = min<ll>(ans, n - gps[1].first - kps[0].first);
	}
	cout << ans <<"\n";
	return 0;
}
