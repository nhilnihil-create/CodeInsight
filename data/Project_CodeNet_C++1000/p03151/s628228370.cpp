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



i64 n, a[101010], b[101010];
void solve(){
	cin >> n;
	i64 sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	i64 cnt = 0, ans = 0;
	for(int i = 0; i < n; i++){
		cin >> b[i];
		sum -= b[i];
		a[i] -= b[i];
		if(a[i] < 0){
			cnt += a[i];
			ans++;
		}
	}
	if(sum < 0){
		cout << -1 << endl;
		return;
	}
	sort(a,a+n, greater<i64>());
	
	for(int i = 0; i < n; i++){
		if(cnt >= 0) break;
		cnt += a[i];
		ans++;
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
