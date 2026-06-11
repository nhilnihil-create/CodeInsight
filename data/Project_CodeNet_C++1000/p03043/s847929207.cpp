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
	int n, k;
	cin >> n >> k;
	double ans = 0;
	for(int i = 1; i <= n; ++i){
		double p = 1.0 / (double)(n);
		int j = i;
		while(j < k){
			p /= 2;
			j *= 2;
		}
		ans += p;
	}
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}
