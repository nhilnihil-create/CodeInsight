#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0);
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//ll pas[5001][5002];


signed main(){
	IOS
	ll n;
	string s;
	cin >> n >> s;
	string s1 = s.substr(0, n), s2 = s.substr(n, n);
	reverse(s2.begin(), s2.end());
	map<pair<string, string>, ll> mp;
	for (ll i = 0;i < (1 << n);++i){
		string t1 = "", t2 = "";
		for (int j = 0;j < n;++j) {
			if((i >> j) & 1)t1 = t1 + s1[j];
			else t2 = t2 + s1[j];
		}
		reverse(t2.begin(), t2.end());
		mp[make_pair(t1, t2)]++;
	}
	ll ans = 0;
	for (ll i = 0;i < (1 << n);++i){
		string t1 = "", t2 = "";
		for (int j = 0;j < n;++j) {
			if((i >> j) & 1)t1 = t1 + s2[j];
			else t2 = t2 + s2[j];
		}
		reverse(t2.begin(), t2.end());
		ans += mp[make_pair(t1, t2)];
	}
	cout << ans << endl;
	
}