#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<P> sushi;
	rep(i,n){
		int t;
		ll d;
		cin >> t >> d;
		sushi.emplace_back(d, t);
	}
	sort(sushi.rbegin(), sushi.rend());
	ll sum = 0, ans = 0, kind = 0;
	priority_queue<P> pq;
	vector<int> cnt(n+1, 0);
	rep(i,k){
		++kind;
		if(cnt[sushi[i].second]++ > 0){
			pq.push(P(-sushi[i].first, sushi[i].second));
			--kind;
		}
		sum += sushi[i].first;
	}
	ans = sum + kind * kind;
	for(int i = k; i < n; ++i){
		if(cnt[sushi[i].second] > 0) continue;
		if(pq.empty()) break;
		ll d = -pq.top().first;
		int t = pq.top().second;
		pq.pop();
		sum = sum - d + sushi[i].first;
		++cnt[sushi[i].second];
		--cnt[t];
		++kind;
		chmax(ans, sum + kind * kind);
	}
	cout << ans << endl;
	return 0;
}
