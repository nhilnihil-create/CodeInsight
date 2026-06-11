#include <bits/stdc++.h>
#define pb push_back
#define ers erase
#define ins insert
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
#define kill(x) return cout << x, 0;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;


const ld Pi = 3.14159265359;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll MAXN = 2e5 + 10;
const ll INF = 1e18;
ll po(ll x, ll t){
	if (t == 0) return 1;
	if (t % 2 == 1) return (x * po((x * x), t / 2));
	return po((x * x), t / 2);
	
}

ll n, p;
int main(){
	IOS;
	cin >> n >> p;
	ll Cnt;
	ll ans = 1;
	if (n == 1) kill(p);
	for (int i = 2; i <= 1000000; i++){
		ll PP = p;
		Cnt = 0;
		while (p % i == 0){
			Cnt ++;
			p /= i;
		}
		ans *= (po(i, Cnt / n));
		
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


