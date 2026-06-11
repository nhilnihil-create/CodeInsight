#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (int)(s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
constexpr long long INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}
#define IN(a, x, b) (a<=x && x<b)

signed main(){
	int N;
	cin >> N;
	multiset<pair<int,int>>l,r;
	vector<int>L(N),R(N);
	REP(i,N){
		cin>>L[i]>>R[i];
		l.insert({L[i],R[i]});
		r.insert({R[i],L[i]});
	}
	int ans = 0,now = 0;
	REP(i,N){
		if(l.empty())break;
		auto ma = prev(l.end());
		l.erase(ma);
		r.erase(r.find({ma->second,ma->first}));
		if(!IN(ma->first,now,ma->second+1)){
			ans += abs(now-ma->first);
			now = ma->first;
		}
		if(l.empty())break;
		auto mi = r.begin();
		r.erase(mi);
		l.erase(l.find({mi->second,mi->first}));
		if(!IN(mi->second,now,mi->first+1)){
			ans += abs(now-mi->first);
			now = mi->first;
		}
	}
	ans += abs(now);
	int aans = ans;
	now = 0;ans = 0;
	REP(i,N){
		l.insert({L[i],R[i]});
		r.insert({R[i],L[i]});
	}
	REP(i,N){
		if(l.empty())break;
		auto mi = r.begin();
		r.erase(mi);
		l.erase(l.find({mi->second,mi->first}));
		if(!IN(mi->second,now,mi->first+1)){
			ans += abs(now-mi->first);
			now = mi->first;
		}
		if(l.empty())break;
		auto ma = prev(l.end());
		l.erase(ma);
		r.erase(r.find({ma->second,ma->first}));
		if(!IN(ma->first,now,ma->second+1)){
			ans += abs(now-ma->first);
			now = ma->first;
		}
	}
	ans += abs(now);
	cout << max(ans,aans) << endl; 
}
