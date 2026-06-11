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
	int k;
	cin >>k;
	
	vector<vector<pii>> r(k);
	rep(i, k){
		r[i].emplace_back((i+1)%k, 1);
		r[i].emplace_back((i*10)%k, 0);
	}
	
	typedef pair<ll, int> pli;
	const ll INF = 1e18;
	priority_queue< pli, vector<pli>, greater<pli> > que;
	vector<ll> d(k, INF);
	d[1] = 1;
	que.emplace(1, 1);
	while(!que.empty()){
		ll cost; int v; tie(cost, v) = que.top(); que.pop();
		if(d[v] < cost) continue;
		for(const auto& rp : r[v]){ 
			int rto = rp.first;
			ll ncst = d[v] + rp.second;
			if(d[rto] > ncst){
				d[rto] = ncst; que.emplace(ncst, rto);
			}
		}
	}	
	cout <<d[0] <<"\n";
	return 0;
}
