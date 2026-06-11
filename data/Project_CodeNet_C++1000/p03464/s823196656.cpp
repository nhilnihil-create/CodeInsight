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
	int k;
	cin >> k;
	vector<ll> a(k);
	rep(i,k) cin >> a[i];
	reverse(a.begin(), a.end());
	int p = 0;
	if(a[0] != 2){
		cout << -1 << endl;
		return 0;
	}
	ll mi = 2, mx = 2;
	rep(p,k){
		if(((mx / a[p] + 1) * a[p] - 1 < mi) || ((mi + a[p] - 1) / a[p] * a[p] > mx)){
			cout << -1 << endl;
			return 0;
		}
		mi = (mi + a[p] - 1) / a[p] * a[p];
		mx = (mx / a[p] + 1) * a[p] - 1;
	}
	cout << mi << " " << mx << endl;
	return 0;
}
