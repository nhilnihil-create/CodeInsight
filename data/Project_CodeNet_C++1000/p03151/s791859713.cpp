#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i,n){
		cin >> a[i];
	}
	int ans = 0;
	ll minus = 0;
	priority_queue<ll> plus;
	rep(i,n){
		cin >> b[i];
		if(a[i] < b[i]){
			++ans;
			minus += b[i] - a[i];
		}
		else{
			plus.push(a[i] - b[i]);
		}
	}
	while(!plus.empty() && minus > 0){
		ll p = plus.top();
		plus.pop();
		minus -= p;
		++ans;
	}
	if(minus <= 0) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}