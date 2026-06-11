#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int digits(ll n){
	if(n == 0) return 1;
	int res = 0;
	while(n > 0){
		n /= 10;
		res++;
	}
	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 1e9;
	for(int i = 1; i <= n-1; ++i){
		int b = n - i;
		int a = i;
		int cmp = 0;
		while(a > 0){
			cmp += a%10;
			a /= 10;
		}
		while(b > 0){
			cmp += b%10;
			b /= 10;
		}
		chmin(ans, cmp);
	}
	cout << ans << endl;
	return 0;
}
