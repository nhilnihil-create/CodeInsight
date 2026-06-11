#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, int> LP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> cnt(5, 0);
	rep(i,n){
		string s;
		cin >> s;
		if(s[0] == 'M') ++cnt[0];
		if(s[0] == 'A') ++cnt[1];
		if(s[0] == 'R') ++cnt[2];
		if(s[0] == 'C') ++cnt[3];
		if(s[0] == 'H') ++cnt[4];
	}
	ll ans = 0;
	for(int i = 0; i <= 2; ++i){
		for(int j = i+1; j <= 3; ++j){
			for(int k = j+1; k <= 4; ++k){
				ans += cnt[i] * cnt[j] * cnt[k];
			}
		}
	}
	cout << ans << endl;
	return 0;
}