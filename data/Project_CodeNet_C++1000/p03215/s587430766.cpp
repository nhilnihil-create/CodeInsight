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



int n, a[1010], k;
i64 d[1010][1010];
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < n; i++){
		i64 cnt = 0;
		for(int j = i; j < n; j++){
			cnt += a[j];
			d[i][j] = cnt;
		}
	}
	
	int b = 0;
	i64 ans = 0;
	for(b = 0; (1LL<<b) < 1000000000000; b++){}
	bool used[1010][1010] = {};
	for(; b >= 0; b--){
		int cc = 0;
		vector<P> v;
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				if(!used[i][j] && d[i][j] >> b & 1){
					cc++;
					v.push_back({i,j});
				}
			}
		}
		if(cc >= k){
			ans += (1LL << b);
			for(int i = 0; i < n; i++){
				for(int j = i; j < n; j++){
					used[i][j] = 1;
				}
			}
			for(int i = 0; i < v.size(); i++){
				used[v[i].first][v[i].second] = 0;
			}
		}
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
