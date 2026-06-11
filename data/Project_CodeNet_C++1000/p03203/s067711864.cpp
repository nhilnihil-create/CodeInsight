#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template < typename T >
void vprint(T &v){
	REP(i, v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
}

map<ll, set<ll>> ma;

int main(){
	ll H, W, N;
	cin >> H >> W >> N;
	ll X, Y;
	REP(i, N){
		cin >> X >> Y;
		ma[X].insert(Y);
	}
	ll left = 1;
	ll right = 1;
	ll res = H;

	for(int i=2;i<=H;i++){
		if(ma[i].empty()) right = min(right+1, W);
		else{
			ll f = *ma[i].begin();
			if(left<=f && f<=right){
				res = i-1;
				break;
			}
			if(f!=right+1) right = min(right+1, W);
		}
	}

	cout << res << endl;

    return 0;
}