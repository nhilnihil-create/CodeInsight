#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }




i64 n, a[10101], b[10101];
P d[10101];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		d[i] = P(a[i]-b[i], i);
	}
	sort(d,d+n);
	
	i64 cnt = 0;
	for(int i = 0; i < n; i++){
		int I = d[i].second;
		if(a[I] == b[I]) continue;
		if(a[I] > b[I]){
			cnt -= a[I]-b[I];
			if(cnt >= 0) continue;
			cout << "No" << endl;
			return;
		}
		cnt += (b[I]-a[I])/2;
	}
	cout << "Yes" << endl;
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
