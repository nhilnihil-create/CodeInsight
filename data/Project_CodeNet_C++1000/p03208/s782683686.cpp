/**
 *    author:  yoseph
 *    created: 18.07.2020 22:41:10      
**/
#include <bits/stdc++.h>
using namespace std;
// === Debug macro starts here ===

int recur_depth = 0;
#ifdef LOCAL
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}

// === Debug macro ends here ===
const int inf = (1 << 31) - 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int > v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(),v.end());
	int ans = inf;
	for (int i = 0; i < n - k + 1; ++i) {
		dbg(ans);
		ans = min(ans,v[i + k - 1] - v[i]);
	}
	cout << ans << "\n";
	return 0;
}
