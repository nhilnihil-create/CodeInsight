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
	double n, m, d;
	cin >> n >> m >> d;
	double ans = (d == 0 ? 1/n : 2*(n-d)/(n*n)) * (m-1);
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}