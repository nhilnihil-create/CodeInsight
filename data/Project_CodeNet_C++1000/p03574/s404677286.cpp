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
int f(vector<vector<char>> s, ll i, ll j, int w, int h){
	if(s[i][j]=='#') return -1;
	int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
	int dy[8] = {0, -1, 1, 1, -1, 0, 1, -1};
	int ans=0;
	rep(k,8){
		ll nx = j+dx[k];
		ll ny = i+dy[k];
		if((nx<0 || nx>w-1) || (ny<0 || ny>h-1)) continue;
		else if (s[ny][nx] == '#') ans+=1;
	}
	return ans;
}
int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> s(h, vector<char>(w));
	rep(i,h) rep(j,w) cin >> s[i][j]; 
	rep(i,h){
		rep(j,w){
			int q = f(s, i, j, w, h);
			if(q==-1) cout << '#';
			else cout << q;
		}
		cout << endl;
	}
 	return 0;
}