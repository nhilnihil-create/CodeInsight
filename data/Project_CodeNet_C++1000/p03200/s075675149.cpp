#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f40;
const long long mod=1e9+7;
const long double PI = acos(0);
template <class T>void UNIQUE(vector<T> &x){
	sort(all(x));
	x.erase(unique(all(x)), x.end());
}

// }}} End Header
int main() {
	string s;
	cin >> s;
	reverse(all(s));
	ll cnt = 0, ans = 0;

	rep(i,s.size()){
		if(s[i] == 'B'){
			ans+=(i-cnt);
			cnt++;
		}
	}


	cout << ans << endl;
	return 0;
}