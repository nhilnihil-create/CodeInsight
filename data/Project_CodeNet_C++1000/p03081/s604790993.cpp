// khodaya khodet komak kon
#include <bits/stdc++.h>
#define pb push_back
#define ers erase
#define ins insert
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
#define kill(x) return cout << x, 0;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;

const ld Pi = 3.14159265359;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll N = 2e5 + 10;
const ll INF = 1e18;
const ll LOG = 20;
ll n, Q;
str s;
vector<pair<char, ll>> Moves;

bool isval(ll x){
	ll pnt = x;
	for (auto u:Moves){
		if (s[pnt] == u.F){
			if (u.S == 'L') pnt--;
			else pnt ++;
		}
		if (pnt == s.size() - 1) return 0;
		if (pnt == 0) return 1;
	}
	return 0;
}


bool isval2(ll x){
	ll pnt = x;
	for (auto u:Moves){
		if (s[pnt] == u.F){
			if (u.S == 'L') pnt--;
			else pnt ++;
		}
		if (pnt == 0) return 0;
		if (pnt == s.size() - 1) return 1;
	}
	return 0;
}

int main(){
	IOS;
	cin >> n >> Q;

	cin >> s;
	s = '.' + s;
	s = s + '.';
	for (int i = 1; i <= Q; i++){
		char c, v;
		cin >> c >> v;
		Moves.pb({c, v});
	}
	
	ll l, r;
	l = 0, r = s.size() - 1;;
	while (r - l > 1){
		ll mid = (r + l) / 2;
		if (isval(mid)) l = mid;
		else r = mid;
	}
	//cout << l << ' ' << r << '\n';
	ll ans = 0;
	ans += l;
	l = 0, r = s.size() - 1;
	while (r - l > 1){
		ll mid = (r + l) / 2;
		if (isval2(mid)) r = mid;
		else l = mid;
	}
	//cout << l << ' ' << r << '\n'; 
	ans += s.size() - 1 - r;
	cout << n - ans;
	
	
	return 0;
}






/*
     ,---,           ___                 ,--,
    '  .' \        ,--.'|_             ,--.'|                             ,--,
   /  ;    '.      |  | :,'            |  | :                           ,--.'|    ,---.        ,---,
  :  :       \     :  : ' :            :  : '                 .--.--.   |  |,    '   ,'\   ,-+-. /  |
  :  |   /\   \  .;__,'  /    ,--.--.  |  ' |     ,--.--.    /  /    '  `--'_   /   /   | ,--.'|'   |
  |  :  ' ;.   : |  |   |    /       \ '  | |    /       \  |  :  /`./  ,' ,'| .   ; ,. :|   |  ,"' |
  |  |  ;/  \   \:__,'| :   .--.  .-. ||  | :   .--.  .-. | |  :  ;_    '  | | '   | |: :|   | /  | |
  '  :  | \  \ ,'  '  : |__  \__\/: . .'  : |__  \__\/: . .  \  \    `. |  | : '   | .; :|   | |  | |
  |  |  '  '--'    |  | '.'| ," .--.; ||  | '.'| ," .--.; |   `----.   \'  : |_|   :    ||   | |  |/
  |  :  :          ;  :    ;/  /  ,.  |;  :    ;/  /  ,.  |  /  /`--'  /|  | '.'\   \  / |   | |--'
  |  | ,'          |  ,   /;  :   .'   \  ,   /;  :   .'   \'--'.     / ;  :    ;`----'  |   |/
  `--''             ---`-' |  ,     .-./---`-' |  ,     .-./  `--'---'  |  ,   /         '---'
                            `--`---'            `--`---'                 ---`-'
*/


