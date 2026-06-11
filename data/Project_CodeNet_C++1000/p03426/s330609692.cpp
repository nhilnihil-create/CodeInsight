#include "bits/stdc++.h"
//#include "atcoder/all"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
//using namespace atcoder;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll memo[90005], num[90005];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w, d;
	cin >> h >> w >> d;
	rep(i,h)rep(j,w){
		int a;
		cin >> a;
		num[a] = i * w + j;
	}
	for(int i = 1; i <= h*w; ++i){
		if(i+d <= h*w){
			int y = num[i] / w;
			int x = num[i] % w;
			int ny = num[i+d] / w;
			int nx = num[i+d] % w;
			memo[i+d] = memo[i] + abs(y - ny) + abs(x - nx);
		}
	}
	int q;
	cin >> q;
	rep(qi,q){
		int l, r;
		cin >> l >> r;
		int ans = memo[r] - memo[l];
		cout << ans << endl;
	}
	return 0;
}
