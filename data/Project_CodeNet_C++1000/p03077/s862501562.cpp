#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll a[5];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll mi = 1e18, cur = -1;
	rep(i,5){
		cin >> a[i];
		if(a[i] <= mi){
			mi = a[i];
			cur = i;
		}
	}
	ll ans = n / mi + 5;
	if(n%mi == 0) --ans;
	cout << ans << endl;
	return 0;
}