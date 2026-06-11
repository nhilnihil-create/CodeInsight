#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n, m, a[10];
int dp[101010], ma[101010];
void solve(){
	cin >> n >> m;
	bool b[10] = {0};
	for(int i = 0; i < m; i++){
		cin >> a[i];
		b[a[i]] = 1;
	}
	int y[10] = {10,2,5,5,4,5,6,3,7,6};
	fill(dp,dp+101010,-INF);
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= 9; j++){
			if(!b[j]) continue;
			if(dp[i+y[j]] == dp[i]+1){
				chmax(ma[i+y[j]], j);
			}
			if(chmax(dp[i+y[j]], dp[i]+1)){
				ma[i+y[j]] = j;
			}
		}
	}
	
	int now = n;
	while(now > 0){
		cout << ma[now]; 
		now -= y[ma[now]];
	}
	cout << endl;
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