#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	ll sum = 0;
	priority_queue<ll> plus;
	ll minus = 0;
	rep(i,n){
		cin >> a[i];
		sum += a[i];
	}
	int ans = 0;
	rep(i,n){
		cin >> b[i];
		if(a[i] > b[i]) plus.push(a[i] - b[i]);
		if(a[i] < b[i]){
			minus += a[i] - b[i];
			++ans;
		}
		sum -= b[i];
	}
	if(sum < 0){
		cout << -1 << endl;
		return 0;
	}
	while(minus < 0){
		minus += plus.top();
		plus.pop();
		++ans;
	}
	cout << ans << endl;
	return 0;
}