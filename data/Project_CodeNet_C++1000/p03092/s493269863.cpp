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
const ll N = 5e3 + 10;
const ll INF = 1e18;
const ll LOG = 20;

ll Place[N][N], a[N], n, A, B;/*Place[i][j] = where is the maximum number in first i element and max <= j*/
ll dp[N][N];/*dp[i][j] = int the first i element answer for the numbers who ai <= j*/
ll inv[N][N];


int main(){
	IOS;
	cin >> n >> A >> B;
	for (int i = 1; i<= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			inv[i][j] = inv[i][j - 1];
			if (a[i] > a[j]) inv[i][j] ++;
		}
	}
	
	
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			Place[i][j] = Place[i - 1][j];
			if (a[i] <= j){
				if (a[i] > a[Place[i - 1][j]]){
					Place[i][j] = i;
				}
				 
			}
			//cout << i << ' ' << j << ' ' << Place[i][j] << '\n';				
		}
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (Place[i][j] == 0) continue;
			dp[i][j] = min(dp[i][a[Place[i][j]] - 1] + A, dp[Place[i][j] - 1][j] + inv[Place[i][j]][i] * B);
		}
	}
	cout << dp[n][n];
	
	
	
	
	
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


