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



int n, a,b,c, d[10];
void solve(){
	cin >> n >> a >> b >> c;
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}
	
	int ans = INF;
	for(int i = 0; i < (1<<(n*2)); i++){
		int sum[4] = {0}, cc[4] = {0};
		for(int j = 0; j < n; j++){
			sum[(i>>(j*2))%4] += d[j];
			cc[(i>>(j*2))%4]++;
		}
		if(cc[0]==0||cc[1]==0||cc[2]==0) continue;
		int cnt = 0;
		cnt += abs(sum[0]-a) + (cc[0]-1)*10;
		cnt += abs(sum[1]-b) + (cc[1]-1)*10;
		cnt += abs(sum[2]-c) + (cc[2]-1)*10;
		chmin(ans,cnt);
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