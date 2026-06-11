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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

vector<ll> V;
map<ll, ll> W;
ll a[MAXN];

void add(ll dig, ll m){
	W[dig]++;
	while(W[dig] >= m){
		W[dig] -= m;
		dig--;
		W[dig] ++;
	}
	return ;
}

void build(){
	W.clear();
	W[1] = 0;
	W[-INF] = 0;
}

void resz(ll sz){
	while( (W.rbegin() -> F) > sz) W.erase(( --W.end() ));
	return ;
}

bool check(ll m){
	build();
	ll cnt = V.size();
	for(int i = 1; i < cnt; i++){
		resz(V[i]);
		add(V[i], m);
		if(W.count(0)) return false;
	}
	return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0;i<n;i++) cin >> a[i];
	V.pb(a[0]);
	for(int i = 1;i<n;i++){
		if(a[i] <= a[i-1]) V.pb(a[i]);
	}
	if(V.size() == 1) return cout << 1, 0;
	ll dw = 1;
	ll up = n;
	ll mid;
	while(dw + 1 < up){
		mid = (dw + up) / 2;
		if(check(mid)) up = mid;
		else dw = mid;
	}
	cout << up;
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

