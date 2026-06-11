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



int n,m,Q;
i64 s[101010], t[101010], x[101010];
void solve(){
	cin >> n >> m >> Q;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	s[0] = -LINF; s[n+1] = LINF;
	for(int i = 1; i <= m; i++){
		cin >> t[i];
	}
	t[0] = -LINF; t[m+1] = LINF;
	
	for(int i = 0; i < Q; i++){
		cin >> x[i];
		i64 *pos = lower_bound(s+1,s+n+1,x[i]);
		i64 *pos2 = lower_bound(t+1,t+m+1,x[i]);
		i64 ans = min(max(*pos,*pos2)-x[i], x[i]-min(*(pos-1),*(pos2-1)));
		chmin(ans, (*pos-x[i])*2+x[i]-*(pos2-1));
		chmin(ans, (*pos2-x[i])*2+x[i]-*(pos-1));
		chmin(ans, (x[i]-*(pos-1))*2+*pos2-x[i]);
		chmin(ans, (x[i]-*(pos2-1))*2+*pos-x[i]);
		cout << ans << endl;
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
