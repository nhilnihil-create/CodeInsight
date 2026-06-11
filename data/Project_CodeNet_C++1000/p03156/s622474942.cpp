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
	int n, a, b;
	cin >> n >> a >> b;
	int c = 0, d = 0, e = 0;
	rep(i,n){
		int p;
		cin >> p;
		if(p <= a) ++c;
		else if(p <= b) ++d;
		else ++e;
	}
	int ans = min({c, d, e});
	cout << ans << endl;
	return 0;
}