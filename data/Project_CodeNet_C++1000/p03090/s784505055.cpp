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




ll n;

int main(){
	cin >> n;
	vector<pii> v;
	auto f = [&](int a,int b){v.push_back({a,b});};
	auto f4 = [&](int a,int b, int aa, int bb){
		f(a,aa);
		f(a,bb);
		f(b,bb);
		f(b,aa);
	};
	
	ll n2 = n/2;
	ll odd = n%2;
	
	rep(i,n2-1){
		ll a = i+1;
		ll aa = i+2;
		ll b = n2*2-i;
		ll bb = n2*2-i-1;
		f4(a,b,aa,bb);
	}
	if ( odd ){
		f(n,1);
		f(n,n2*2);
		if ( n != 3 ){
			f(n,n2);
			f(n,n2+1);
		}
	}
	else {
		if ( n != 4 ){
			f4(n2,n2+1,1,n2*2);
		}
	}
	
	cout << v.size() << endl;
	for ( auto it : v )
		cout << it.first << " " << it.second << endl;
	
	return 0;
}


