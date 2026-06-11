#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n;
string s;
void solve(){
	cin >> n >> s;
	
	i64 ans = 0;
	int b[26] = {0};
	for(int i = 0; i < n; i++){
		i64 cnt = 1;
		for(int j = 0; j < 26; j++){
			if(s[i]-'a' == j) continue;
			else cnt *= b[j]+1;
			cnt %= INF;
		}
		ans += cnt;
		ans %= INF;
		b[s[i]-'a']++;
		//cout << ans << endl;
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
