#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<ll> v(n+2, 0);
	rep(i,n) cin >> v[i+1];
	ll ans = 0;
	for(int l = 0; l <= min(k,n); l++){
		for(int r = 0; r <= min(k-l,n-l); r++){
			priority_queue<ll> pq;
			ll score = 0;
			for(int i = 0; i <= l; i++){
				score += v[i];
				pq.push(-v[i]);
			}
			for(int i = 0; i <= r; i++){
				score += v[n+1-i];
				pq.push(-v[n+1-i]);
			}
			int rest = k - l - r;
			for(int i = 0; i < rest; i++){
				ll p = pq.top();
				pq.pop();
				if(p > 0) score += p;
				else break;
			}
			chmax(ans, score);
		}
	}
	cout << ans << endl;
	return 0;
}
