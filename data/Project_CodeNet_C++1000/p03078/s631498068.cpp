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
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<ll> a(x), b(y), c(z);
	rep(i,x) cin >> a[i];
	rep(i,y) cin >> b[i];
	rep(i,z) cin >> c[i];
	vector<ll> ab;
	rep(i,x)rep(j,y){
		ab.push_back(a[i] + b[j]);
	}
	sort(ab.rbegin(), ab.rend());
	sort(c.rbegin(), c.rend());
	priority_queue<ll> pq;
	rep(i,min(k,x*y))rep(j,min(k,z)){
		pq.push(-(ab[i] + c[j]));
		if(pq.size() > k) pq.pop();
	}
	vector<ll> ans(k);
	for(int i = k-1; i >= 0; --i){
		ans[i] = -(pq.top());
		pq.pop();
	}
	rep(i,k) cout << ans[i] << endl;
	return 0;
}