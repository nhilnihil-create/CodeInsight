#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//#include "atcoder/all"
//using namespace atcoder;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, d, x;
	cin >> n >> d >> x;
	int ans = x;
	rep(i,n){
		int a;
		cin >> a;
		for(int j = 1; j <= d; j+=a) ++ans;
	}
	cout << ans << endl;
	return 0;
}