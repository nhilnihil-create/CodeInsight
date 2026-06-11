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
	int n, k;
	cin >>n >>k;
	vector<pii> td(n);
	for(auto& x: td){ cin >>x.second >>x.first; x.second--; }
	sort(td.rbegin(), td.rend());
	ll sm = 0, psu =0;
	VI cnt(n);
	rep(i, k){
		sm += td[i].first;
		cnt[td[i].second]++;
	}
	rep(i, n) if(cnt[i]>0) psu++;
	sm += psu * psu;
	ll ans = sm;
	int p=k-1, j=k;
	repr(i, p, 0) if(cnt[td[i].second]>=2) {
		for( ;j<n; j++) if(cnt[td[j].second]==0){
			sm -= td[i].first + psu*psu;
			cnt[td[i].second]--;
			psu++;
			sm += td[j].first + psu*psu;;
			cnt[td[j].second]++;
			ans = max(ans, sm);
			break;
		}
	}
	cout <<ans <<"\n";
	return 0;
}
