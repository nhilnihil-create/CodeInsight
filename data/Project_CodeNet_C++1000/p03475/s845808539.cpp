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
	int n;
	cin >> n;
	vector<ll> c(n-1), s(n-1), f(n-1);
	rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
	rep(i,n-1){
		ll time = 0;
		for(int j = i; j < n-1; ++j){
			chmax(time, s[j]);
			if(time%f[j] != 0) time = ((time + f[j] - 1) / f[j]) * f[j];
			time += c[j];
		}
		cout << time << endl;
	}
	cout << 0 << endl;
	return 0;
}
