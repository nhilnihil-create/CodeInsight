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



i64 n, a[101010];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	if(a[n-1] != 2){
		cout << -1 << endl;
		return;
	}
	i64 cnt = 2, ma = 3;
	for(int i = n-2; i >= 0; i--){
		if(cnt < 2 || a[i] > ma){
			cout << -1 << endl;
			return;
		}
		cnt = (cnt+a[i]-1)/a[i] * a[i];
		if(cnt - cnt%a[i+1] > ma){
			cout << -1 << endl;
			return;
		}
		//chmax(ma, cnt+a[i]-1);
		/*if(ma%a[i] > 0)*/ chmax(ma, ma + a[i]-ma%a[i]-1);
		//cout << cnt << " " << ma << endl;
	}
	cout << cnt << " " << ma << endl;
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
