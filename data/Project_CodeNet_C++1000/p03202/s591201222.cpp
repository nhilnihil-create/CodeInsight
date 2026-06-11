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
vector<ll> a;

struct sdata {
	ll len;
	ll count;
};

ll mpow_table[64]; // mのべき乗

vector<sdata> v;

void dump(){
	return;
	eprintf( "len=%d ", SZ(v) );
	for ( auto it : v )
		eprintf( "[%lld %lld] ", it.len, it.count );
	eprintf( "\n" );
}

bool is_possible(ll m){
	ll mp = 1;
	rep(i,64){
		mpow_table[i] = mp;
		mp = min(mp*m,200001LL);
	}
	auto mpow = [&](ll p){
		if ( m == 1 )
			return 1LL;
		if ( p < 64 )
			return mpow_table[p];
		return 200001LL;
	};
	
	v.resize(0);
	
	ll keta = 0;
	
	eprintf("\n\nm=%lld\n", m );
	rep(i,n){
		dump();
		if ( keta < a[i] ){
			v.push_back({a[i]-keta,0});
			keta = a[i];
		}
		else {
			// v.top の桁を狭める
			while ( keta - v.back().len >= a[i] ){
				keta -= v.back().len;
				v.pop_back();
			}
			
			ll keta_reduce = keta-a[i];
			
			rep(j,keta_reduce){
				v.back().count /= m;
				if ( v.back().count == 0 )
					break;
			}
			v.back().len -= keta_reduce;
			keta -= keta_reduce;
			
			v.back().count++;
			while ( v.back().count >= mpow(v.back().len) ){
				keta -= v.back().len;
				v.pop_back();
				if ( v.empty() )
					return false;
				v.back().count++;
			}
		}
	}
	dump();
	return true;
}



int main(){
	cin >> n;
	a.resize(n);
	rep(i,n) {
		cin >> a[i];
	}
	
	// l種類では不可能、h種類では可能.
	ll h = 200001;
	ll l = 0;
	
	while ( h-l > 1 ){
		ll m = l + (h-l)/2;
		if ( is_possible(m) )
			h = m;
		else
			l = m;
	}
	
	cout << h << endl;
	
	return 0;
}


