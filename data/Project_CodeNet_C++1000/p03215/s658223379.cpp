#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 1e6 + 7;
const int Inf = 1 << 30;
const ll INF = 1ll << 60;
#define mst(x) memset(x, 0, sizeof(x))
priority_queue <int> qua;
ll a[maxx];
vector <ll> vec;
int n, k;
ll ans;
 
void Init() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		ll sum = 0;
		for(int j = i; j <= n; j++) {
			sum += a[j];
			vec.push_back(sum);
		}
	}
}
 
void solve() { 
	for(int bit = 59; bit >= 0; bit--) {
		int cnt = 0; 
		int sz = vec.size();
		for(int i = 0; i < sz; i++) {
			ll dd = 1ll << bit;
			if(vec[i] & dd) cnt++;
		}
		if(cnt < k) continue;
		vector <ll> tmp;
		tmp.clear();
		for(int i = 0; i < sz; i++) {
			ll dd = 1ll << bit;
			if(vec[i] & dd) tmp.push_back(vec[i]);
		}
		vec = tmp; 
		ans += 1ll << bit;
	}
}
 
int main() {
	Init();
	solve();
	cout << ans << endl;
}