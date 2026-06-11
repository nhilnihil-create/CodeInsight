#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
// }}} End Header

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int M = 0;
	loop(i, 1, n){
		int cnt = 0;
		string s1 = s.substr(0, i);
		string s2 = s.substr(i, n-i);
		map<char, int> t;
		for(auto x : s1) if(t[x]==0) t[x]++;
		for(auto y : s2) if(t[y]==1) t[y]++;
		for(auto z : t) if(z.second == 2) cnt++;
		M = max(cnt, M);
	}
	cout << M << endl;
 	return 0;
}