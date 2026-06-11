#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 3e2 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll dp[2][MAXN][MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s;
	cin >> s;
	ll n = s.size();
	s = '!' + s;
	ll k;
	cin >> k;
	ll ii, t, ans = 1;
	for(int i = 1; i <= n; i++){
		ii = i & 1;
		//debug(i);
		memset(dp[ii], 0, sizeof dp[ii]);
		for(int j = n; j > i; j--){
			if(s[i] == s[j]) t = 2;
			else t = 0;
			
			dp[ii][j][0] = max({dp[1 - ii][j][0], dp[1 - ii][j + 1][0] + t, dp[ii][j + 1][0]});
			for(int l = 1; l <= k; l++){
				dp[ii][j][l] = max({dp[1 - ii][j][l], dp[1 - ii][j + 1][l] + t, dp[ii][j + 1][l]});
				dp[ii][j][l] = max(dp[ii][j][l], dp[1 - ii][j + 1][l - 1] + 2);
				ans = max(ans, dp[ii][j][l] + (i + 1 < j ? 1 : 0));
			}
			ans = max(ans, dp[ii][j][0] + (i + 1 < j ? 1 : 0));
		}
	}
	cout << ans;
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
