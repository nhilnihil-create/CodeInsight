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



int n;
vector<int> v[202020];
bool used[202020];
int ans = 0;
int dfs(int x){
	int ma = 0, ma2 = 0, cnt;
	for(int i = 0; i < v[x].size(); i++){
		if(used[v[x][i]]) continue;
		used[v[x][i]] = 1;
		cnt = dfs(v[x][i])+1;
		if(chmax(ma2,cnt)){
			if(ma < ma2) swap(ma,ma2);
		}
	}
	chmax(ans, ma+ma2);
	return ma;
}

void solve(){
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int a,b;
		cin >> a >> b;
		a--; b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	used[0] = 1;
	dfs(0);
	if(ans%3 & 1){
		cout << "Second" << endl;
	}
	else{
		cout << "First" << endl;
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
