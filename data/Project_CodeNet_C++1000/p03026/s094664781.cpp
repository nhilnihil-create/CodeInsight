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



int n, c[10101], e[10101], a[10101], b[10101];
P d[10101];
vector<int> v[10101];
bool used[10101];
int cnt = 0;
void dfs(int pos){
	for(int i = 0; i < v[pos].size(); i++){
		int I = v[pos][i];
		if(used[I]) continue;
		used[I] = 1;
		dfs(I);
	}
	e[pos] = c[cnt];
	cnt++;
}
void solve(){
	cin >> n;
	for(int i = 0; i < n-1; i++){
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
	}
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	sort(c,c+n);
	
	used[0] = 1;
	dfs(0);
	i64 ans = 0;
	for(int i = 0; i < n-1; i++){
		ans += min(e[a[i]], e[b[i]]);
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++){
		cout << e[i] << " ";
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
