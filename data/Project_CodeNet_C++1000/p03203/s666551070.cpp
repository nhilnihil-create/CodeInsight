#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) do{}while(0)
#endif







ll h, w, n;
vector<vector<ll>> v;

int main(){
	cin >> h >> w >> n;
	
	v.resize(w);
	rep(i,n){
		ll x, y;
		cin >> x >> y;
		x--;
		y--;
		v[y].push_back(x);
	}
	
	rep(i,w)
		sort(ALL(v[i]));
	
	
	// 下方向の障害物のxを返す
	auto xblock = [&](ll px, ll py){
		auto it = lower_bound(v[py].begin(),v[py].end(),px);
		if ( it == v[py].end() )
			return h;
		return *it;
	};
	
	
	ll x = 0;
	ll y = 0;
	ll minx = h;
	while ( true ){
		ll bx = xblock(x,y);
		chmin( minx, bx );
		
		//eprintf( "%lld %lld bx=%lld \n", x+1, y+1, bx );
		// 高橋君は、移動できるなら常に移動する
		if ( bx == x+1 )
			break;
		x++;
		
		if ( y == w-1 || xblock(x,y+1) == x ){ // 右に移動できない
			;
		}
		else {
			y++;
		}
	}
	
	cout << minx << endl;
	
	
	return 0;
}


