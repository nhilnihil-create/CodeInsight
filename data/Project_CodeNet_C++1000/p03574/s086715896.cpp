#include<bits/stdc++.h>
//#include<atcoder/all>
// Begin Header {{{
//using namespace atcoder;
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
template<class T, class S> inline bool chmax(T &a, const S &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T, class S> inline bool chmin(T &a, const S &b) { if (a>b) { a = b; return 1; } return 0; }
template<class T> void scan(T &a) { cin >> a; }
void IN() {}
template<class Head, class... Tail> void IN(Head &head, Tail &... tail){ scan(head); IN(tail...); }
// }}} End Header
int main() {
	int dx[9] = {1, 1, 1, 0, 0, -1, -1, -1};
	int dy[9] = {0, 1, -1, 1, -1, 1, 0, -1};
	ll h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i,h) cin >> s[i];

	rep(i,h){
		rep(j,w){
			if(s[i][j] == '#') continue;
			int cnt=0;
			rep(t, 9){
				if(i+dx[t] < 0 || i+dx[t] >=h || j+dy[t] < 0 || j+dy[t]>=w) continue;
				if(s[i+dx[t]][j+dy[t]] == '#') cnt++;
			}
			s[i][j] = char('0'+cnt);
		}
	}
	rep(i,h) cout << s[i] << endl;
	return 0;
}
