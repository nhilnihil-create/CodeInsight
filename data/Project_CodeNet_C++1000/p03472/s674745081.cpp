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
	int n, h;
	cin >> n >> h;
	vector<int> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	int ans = 0, idx = 0;
	while(h > 0 && idx < n && a[0] < b[idx]){
		h -= b[idx++];
		++ans;
	}
	if(h > 0) ans += (h + a[0] - 1) / a[0];
	cout << ans << endl;
	return 0;
}
