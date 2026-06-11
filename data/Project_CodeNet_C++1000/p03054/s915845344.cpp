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




bool can_drop( ll w, ll sc, char L, char R, string s, string t ){
	int len = s.size();
	int pos = sc-1;
	int l = 0;
	int r = w;
	
	// posが[l,r) にあるなら駒が残る
	for ( int i = len-1; i >= 0; i-- ){
		// 後手 許容範囲を広げる
		if ( t[i] == R && 0 < l ) l--;
		if ( t[i] == L && r < w ) r++;
		
		// 先手 許容範囲を狭める
		if ( s[i] == R ) r--;
		if ( s[i] == L ) l++;
		
		if ( r <= l )
			return true;
	}
	if ( pos < l || r <= pos )
		return true;
	
	return false;
}



int main(){
	ll h, w, n, sr, sc;
	string s, t;
	
	cin >> h >> w >> n;
	cin >> sr >> sc;
	cin >> s;
	cin >> t;
	
	if ( can_drop( h, sr, 'U', 'D', s, t ) ||
	     can_drop( w, sc, 'L', 'R', s, t ) )
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	
	
	return 0;
}


