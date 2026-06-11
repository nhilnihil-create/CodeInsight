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
string s;
int u[26];
i64 mod_pow(i64 x, i64 y, i64 mod){
	i64 res = 1;
	while(y > 0){
		if(y & 1) res = res * x % mod;
		x = x*x %mod;
		y >>= 1;
	}
	return res;
}
void solve(){
	cin >> n >> s;
	
	i64 a = 0;
	for(int i = 0; i < n; i++){
		i64 c = 1;
		for(int j = 0; j < 26 ;j++){
			if(s[i]-'a' == j) continue;
			if(!u[j]) continue;
			c += c*u[j];
			c %= INF;
		}
		a+=c;
		a%=INF;
		u[s[i]-'a']++;
	}
	cout << a << endl;
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
