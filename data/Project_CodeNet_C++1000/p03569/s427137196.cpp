#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



string s;
void solve(){
	cin >> s;
	int n = s.size();
	
	string t;
	for(int i = 0; i < n; i++){
		if(s[i] == 'x') continue;
		t += s[i];
	}
	
	int m = t.size();
	for(int i = 0; i < m/2; i++){
		if(t[i] != t[m-i-1]){
			cout << -1 << endl;
			return;
		}
	}
	int l = 0, r = n-1;
	int ans = 0;
	while(l < r){
		if(s[l] == s[r]){
			l++; r--;
			continue;
		}
		if(s[l] == 'x'){
			ans++;
			l++;
			continue;
		}
		if(s[r] == 'x'){
			ans++;
			r--;
			continue;
		}
	}
	cout << ans << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
