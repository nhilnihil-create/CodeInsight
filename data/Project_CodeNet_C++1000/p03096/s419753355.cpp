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
vector<ll> v;
vector<ll> c;
vector<ll> c_prevpos;
vector<ll> pos_prevpos;


const ll MOD = 1e9+7;

int main(){
	cin >> n;
	
	v.resize(n);
	c.resize(n);
	c_prevpos.resize(200001,-1);
	pos_prevpos.resize(n,-1);
	
	rep(i,n){
		cin >> c[i];
		pos_prevpos[i] = c_prevpos[c[i]];
		c_prevpos[c[i]] = i;
	}
	
	v[0] = 1;
	for ( int i = 1; i < n; i++ ){
		// v[i] は c[0..i] の塗り方の数
		int p = pos_prevpos[i];
		if ( p != -1 && p != i-1 )
			v[i] = (v[i-1] + v[p])%MOD;
		else
			v[i] = v[i-1];
	}
	
	
	cout << v[n-1] << endl;
	
	return 0;
}


