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

ll ans, aa, b, c, d, n, a[N], par[N];
int main(){
	IOS;
	cin >> n;
	ans = INF;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		par[i] = par[i - 1] + a[i];
	}
	for (int i = 2; i <= n - 2; i++){
		ll l = 1, r = i;
		aa = a[1], b = par[i] - a[1];
		//cout << i << '\n';
  		while (r - l > 1){
			ll mid = (l + r) / 2;
			//cout << mid << ' ';
			if (abs(par[mid] - par[i] + par[mid]) < abs(aa - b)){
				aa = par[mid], b = par[i] - par[mid]; 
				//cout << "BOZ\n";
			}
			if (par[mid] > par[i] - par[mid]){
				r = mid;
			}else{
				l = mid;
			}
			
		}
		c = a[i + 1], d = par[n] - par[i + 1];
		l = i + 1, r = n;
		//cout << endl;
		//cout << i << ' ' << aa << ' ' << b << ' ' << c << ' ' << d << '\n'; 
 		while (r - l > 1){
			ll mid = (l + r) / 2;
			if (abs(par[mid] - par[i] - (par[n] - par[mid])) < abs(c - d)){
				c = par[mid] - par[i], d = par[n] - par[mid];
			}
			if (par[mid] - par[i] > (par[n] - par[mid])) r = mid;
			else l = mid;
		}
  		ans = min(ans, max({aa, b, c, d}) - min({aa, b, c, d}));
		
	}
	cout << ans;
	
	
	
	
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


