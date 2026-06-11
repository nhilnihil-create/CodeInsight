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
string s[303];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	
	int cnt = 0;
	for(int k = 0; k < n; k++){
		bool b = 1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(s[mod(i+k,n)][j] != s[mod(j+k,n)][i]) b = 0;
			}
		}
		
		if(b) cnt+=n;
	}
	cout << cnt << endl;
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
