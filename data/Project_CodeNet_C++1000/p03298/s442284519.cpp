#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;
#define rot first
#define blau second
#define comb second

int main(){
	int n; cin >> n;
	string s; cin >> s;
	auto halb = s.begin();
	for( int i = 0; i < n; ++i ) ++halb;
	reverse( halb, s.end() );
	map<pair<string, string>, ll> l_mp;
	map<pair<string, string>, ll> r_mp;
	for( int cond = 0; cond < (1<<n); ++cond ){
		string l_rot = "", l_blau = "", r_rot = "", r_blau = "";
		for( int i = 0; i < n; ++i ){
			if( cond & (1<<i) ){
				l_rot += s[i];
				r_rot += s[n+i];
			} else {
				l_blau += s[i];
				r_blau += s[n+i];
			}
		}
		++l_mp[make_pair(l_rot, l_blau)];
		++r_mp[make_pair(r_rot, r_blau)];
	}
	ll ans = 0;
	for( auto &mp : l_mp ){
		// 左半分を赤で塗った文字列と右半分を青で塗った文字列が同じ ∧ 左半分を青で塗った文字列と右半分を赤で塗った文字列が同じ
		ans += mp.comb * r_mp[make_pair(mp.first.blau, mp.first.rot)];
		// if( r_mp[make_pair(mp.first.blau, mp.first.rot)] == 1 ) cout << mp.first.blau << ' ' << mp.first.rot << ' ' << mp.comb << endl;
	}
	cout << ans << endl;
}