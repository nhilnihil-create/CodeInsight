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
	ll N;
	cin >> N;
	for(ll h = 1; h <= 3500; ++h){
		for(ll n = 1; n <= 3500; ++n){
			ll a = N*h*n;
			ll b = 4*h*n - N*n - N*h;
			if(b <= 0) continue;
			if(a%b != 0) continue;
			ll w = a / b;
			cout << h << " " << n << " " << w << endl;
			return 0;
		}
	}
	return 0;
}
