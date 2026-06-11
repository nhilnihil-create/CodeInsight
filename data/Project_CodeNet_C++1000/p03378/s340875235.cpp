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
	int n, m, x;
	cin >> n >> m >> x;
	int l = 0, r = 0;
	rep(i,m){
		int a;
		cin >> a;
		if(a < x) ++l;
		else ++r;
	}
	int ans = min(l, r);
	cout << ans << endl;
	return 0;
}