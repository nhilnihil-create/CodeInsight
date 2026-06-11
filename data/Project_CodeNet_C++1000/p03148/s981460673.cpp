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



i64 n, k, a[101010], b[101010];
P p[101010];
bool used[101010];
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		a[i]--;
		p[i] = {b[i],a[i]};
	}
	sort(p,p+n, greater<P>());
	
	i64 ans = 0, cnt = 0;
	stack<i64> st;
	for(int i = 0; i < k; i++){
		i64 c = p[i].first, pos = p[i].second;
		ans += c;
		if(used[pos]){
			st.push(c);
			continue;
		}
		used[pos] = 1;
		cnt++;	
	}
	i64 aans = ans;
	ans += cnt*cnt;
	for(int i = k; i < n; i++){
		if(st.empty()) break;
		i64 c = p[i].first, pos = p[i].second;
		if(used[pos]) continue;
		used[pos] = 1;
		cnt++;
		aans += c - st.top();
		chmax(ans, aans+cnt*cnt);
		st.pop();
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
