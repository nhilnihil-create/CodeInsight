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



int n, k, a[202020];
int d[202020];
void solve(){
	cin >> n >> k;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(d[a[i]] == 0) cnt++;
		d[a[i]]++;
	}
	sort(d,d+n+1);
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(d[i] == 0) continue;
		if(cnt <= k) break;
		cnt--;
		ans += d[i];
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