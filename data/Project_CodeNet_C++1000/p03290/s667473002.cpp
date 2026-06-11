#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int d;
	ll g;
	cin >> d >> g;
	vector<ll> p(d), c(d);
	rep(i,d) cin >> p[i] >> c[i];
	int ans = 1e9;
	rep(S,(1<<d)){
		ll score = 0;
		int cnt = 0, next = -1;
		rep(j,d){
			if(S>>j & 1){
				score += p[j] * (j+1) * 100 + c[j];
				cnt += p[j];
			}
			else{
				next = j;
			}
		}
		if(score >= g) chmin(ans, cnt);
		if(next == -1) continue;
		rep(k,p[next]){
			if(score >= g) break;
			score += 100*(next+1);
			++cnt;
		}
		if(score >= g) chmin(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}