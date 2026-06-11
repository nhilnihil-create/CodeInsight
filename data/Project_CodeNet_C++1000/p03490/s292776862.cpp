#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> node;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 2e5 + 10;
const int Maxk = 60;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

bitset<16032> X, Y;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	X[0] = Y[0] = true;
	str s;
	cin >> s;
	s += 'T';
	ll fx, fy;
	cin >> fx >> fy;
	ll smx = 0, smy = 0;
	
	ll cnt = 0;
	ll f = 0, f2 = 0;
	for(auto x : s){
		if(x == 'T'){
			if(!f){
				smx += cnt;
				if(f2){
					X |= (X << (2 * cnt));
				}
			} else {
				smy += cnt;
				Y |= (Y << (2 * cnt));
			}
			cnt = 0;
			f = 1 - f;
			f2 = 1;
		} else {
			cnt ++;
		}
	}
	if(smx < fx || smy < fy) cout << "No\n";
	else cout << (X[smx - fx] & Y[smy - fy] ? "Yes\n" : "No\n");
	return 0;
}

/*

                                 ____              ,----..               ,----..
   ,---,                       ,'  , `.           /   /   \             /   /   \
  '  .' \                   ,-+-,.' _ |          /   .     :           /   .     :
 /  ;    '.              ,-+-. ;   , ||         .   /   ;.  \         .   /   ;.  \
:  :       \            ,--.'|'   |  ;|        .   ;   /  ` ;        .   ;   /  ` ;
:  |   /\   \          |   |  ,', |  ':        ;   |  ; \ ; |        ;   |  ; \ ; |
|  :  ' ;.   :         |   | /  | |  ||        |   :  | ; | '        |   :  | ; | '
|  |  ;/  \   \        '   | :  | :  |,        .   |  ' ' ' :        .   |  ' ' ' :
'  :  | \  \ ,'        ;   . |  ; |--'         '   ;  \; /  |        '   ;  \; /  |
|  |  '  '--'          |   : |  | ,             \   \  ',  /          \   \  ',  /
|  :  :                |   : '  |/               ;   :    /            ;   :    /
|  | ,'                ;   | |`-'                 \   \ .'              \   \ .'
`--''                  |   ;/                      `---`                 `---`
                       '---'

*/
