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



i64 n, m, a[1010], b[1010], c[1010];
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	
	i64 ans = 0;
	for(int i = 0; i < 8; i++){
		int bb[3] = {};
		for(int j = 0; j < 3; j++){
			bb[j] = (i>>j&1);
		}
		i64 p[1010];
		for(int j = 0; j < n; j++){
			i64 cnt = (1-2*bb[0])*a[j];
			cnt += (1-2*bb[1])*b[j];
			cnt += (1-2*bb[2])*c[j];
			p[j] = cnt;
		}
		sort(p,p+n,greater<i64>());
		i64 cc = 0;
		for(int j = 0; j < m; j++){
			cc += p[j];
		}
		chmax(ans,cc);
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