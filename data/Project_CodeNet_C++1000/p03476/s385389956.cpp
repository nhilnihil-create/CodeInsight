#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool isPrime(ll n){
	for(ll i = 2; i*i <= n; i++){
		if(n%i == 0) return false;
	}
	return true;
}

int sum[100005];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	for(int i = 3; i <= 100001; ++i){
		sum[i] = sum[i-1];
		if(isPrime(i) && isPrime((i+1)/2)) ++sum[i];
	}
	int q;
	cin >> q;
	rep(qi,q){
		int l, r;
		cin >> l >> r;
		cout << sum[r] - sum[l-1] << endl;
	}
	return 0;
}