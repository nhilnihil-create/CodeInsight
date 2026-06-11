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
	int n, z, w;
	cin >> n >> z >> w;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	int ans = abs(a[n-1] - w);
	if(n >= 2) ans = max(abs(a[n-1] - w), abs(a[n-1] - a[n-2]));
	cout << ans << endl;
	return 0;
}