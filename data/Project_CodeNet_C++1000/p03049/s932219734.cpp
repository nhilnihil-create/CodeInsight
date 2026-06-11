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
	int ans = 0, a = 0, b = 0, ba = 0;
	rep(i,n){
		string s;
		cin >> s;
		rep(j,s.size()-1){
			if(s[j] == 'A' && s[j+1] == 'B') ++ans;
		}
		if(s[0] == 'B' && s.back() == 'A') ++ba;
		else if(s[0] == 'B') ++b;
		else if(s.back() == 'A') ++a;
	}
	if(a > 0){
		ans += ba;
		ba = 0;
	}
	else if(ba > 0){
		ans += ba - 1;
		ba = 0;
		++a;
	}
	ans += min(a, b);
	cout << ans << endl;
	return 0;
}