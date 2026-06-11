#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
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
const ll MAXN = (ll) 5e3 + 100;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll a[MAXN], dp[MAXN], ind[MAXN];
vector<ll> fr;


ll BS2(ll x){
	ll l = -1, r = fr.size();
	ll mid;
	while(l + 1 < r){
		mid = (l + r) / 2;
		if(fr[mid] < x) l = mid;
		else r = mid;
	}
	return fr.size() - r;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, A, B;
	cin >> n >> A >> B;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ind[a[i]] = i;
	}
	
	memset(dp, 31, sizeof dp);
	dp[0] = 0;
	a[0] = -1;
	ll ans = n * A;
	for(int i = 1; i <= n; i++){
		ll ca = 0;
		ll cb = 0;
		fr.clear();
		for(int j = i + 1; j <= n; j++) fr.pb(a[j]);
		sort(all(fr));
		for(int j = i - 1; j > 0; j--){
			if(a[j] < a[i]){
				ll cnt = BS2(a[j]) - BS2(a[i]);
				dp[i] = min(dp[i], dp[j] + cnt * B + ((a[i] - a[j] - 1) - cnt) * A);
			}
		}
		dp[i] = min(dp[i], B * (a[i] - 1));
		ans = min(ans, dp[i] + (n - a[i]) * A);
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


