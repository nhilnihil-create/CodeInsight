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



int n;
string s[101010];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	
	int ans = 0, a = 0, b = 0;
	int c = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < s[i].size(); j++){
			if(s[i][j] == 'A' && s[i][j+1] == 'B') ans++;
		}
		bool bb = 0,aa = 0;
		if(s[i][0] == 'B') b++, bb = 1;
		if(*(s[i].end()-1) == 'A') a++, aa = 1;
		if(bb && aa) c++;
	}
	
	if(max(a,b) == c) ans += max(c-1,0);
	else ans += min(a,b);
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
