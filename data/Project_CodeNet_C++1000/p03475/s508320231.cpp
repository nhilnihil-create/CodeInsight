#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n, a[505], b[505], c[505];
void solve(){
	cin >> n;
	for(int i = 1; i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = i; j < n; j++){
			cnt = max(b[j], (cnt+c[j]-1)/c[j]*c[j]);
			cnt += a[j];
		}
		cout << cnt << endl;
	}
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