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
    #define eprintf(...) {}
#endif





ll n;

int main(){
	cin >> n;
	map<ll,int> m;
	set<ll,greater<ll>> s;
	
	rep(i,n){
		ll a;
		cin >> a;
		m[a]++;
		s.insert(a);
	}
	
	ll ct = 0;
	for ( auto x : s ){
		ll b = 1;
		while ( b <= x )
			b *= 2;
		ll y = b - x;
		
		if ( s.count(y) ){
			if ( x != y ){
				while ( m[x] && m[y] ){
					m[x]--;
					m[y]--;
					ct++;
					eprintf( " %lld %lld\n", x, y );
				}
			}
			else {
				while ( m[x] >= 2 ){
					m[x] -= 2;
					ct++;
					eprintf( " %lld %lld\n", x, y );
				}
			}
		}
	}
	
	cout << ct << endl;
	
	return 0;
}


