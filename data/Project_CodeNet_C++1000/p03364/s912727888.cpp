#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i,n) cin >> s[i];
	int ans = 0;
	rep(k,n){
		bool ok = true;
		rep(i,n){
			for(int j = i+1; j < n; ++j){
				if(s[i][(j+k)%n] != s[j][(i+k)%n]) ok = false;
			}
		}
		if(ok) ans += n;
	}
	cout << ans << endl;
	return 0;
}