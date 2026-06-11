#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

int main()
{
	int h, w,d;
	cin >> h >> w >>d;
	map<int,P> mp;
	rep(i,h){
		rep(j,w){
			int a;
			cin >> a;
			mp[a] = {i,j};
		}
	}
	ll cost[h*w+1];
	for(int i = 1; i <= h * w; i++) {
		if(i <= d) {
			cost[i] = 0;
			continue;
		}
		cost[i] = cost[i-d] + abs(mp[i].first - mp[i-d].first) + abs(mp[i].second - mp[i-d].second);
	}
	int q;
	cin >> q;
	rep(i,q){
		int l, r;
		cin >> l >> r;
		cout << cost[r] - cost[l] << endl;
	}
}
