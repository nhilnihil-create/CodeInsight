#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n,k;
int t[101010], d[101010];
P p[101010];
i64 kind[101010], sk = 0;
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> t[i] >> d[i];
		p[i] = P(d[i],t[i]);
	}
	sort(p,p+n,greater<P>());
	
	i64 cnt = 0, ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < k; i++){
		if(kind[p[i].second] == 0) sk++;
		if(kind[p[i].second] > 0) pq.push(p[i].first);
		kind[p[i].second]++;
		cnt += p[i].first;
	}
	cnt += sk*sk;
	chmax(ans, cnt);
	
	for(int i = k; i < n; i++){
		if(pq.empty()) break;
		if(kind[p[i].second] == 0){
			int q = pq.top(); pq.pop();
			sk++;
			kind[p[i].second]++;
			cnt = cnt-q+sk*2-1 + p[i].first;
			chmax(ans, cnt);
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
