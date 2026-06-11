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
const ll MOD = 998244353;
const ll N = 3e5 + 10;
const ll INF = 1e18;
const ll LOG = 20;
ll fac[N], im[N];
ll POW_MOD(ll x, ll t){
	if (t == 0){
		return 1;
	}
	if (t % 2 == 0){
		return (POW_MOD((x * x) % MOD, t / 2));
	}else{
		return (x * POW_MOD(x, t - 1)) % MOD;
	}
}

ll CHOOSE(ll n, ll c){
	if (c > n) return 0;
	ll ans = fac[n] * im[c];
	ans %= MOD;
	ans *= im[n - c];
	ans %= MOD;
	return ans;
}





int main(){
	IOS;
	fac[0] = 1;
	ll n, A, B, K;
	for (int i = 1; i < N; i++){
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	for (int i = 0; i < N; i++){
		im[i] = POW_MOD(fac[i], MOD - 2);
	}
	ll ans = 0;
	cin >> n >> A >> B >> K;
	for (int i = 0; i <= n; i++){
		ll magh;
		if (K < A * i){
			break;
		}
		if ((K - A * i) % B == 0 && (K - A * i) / B <= n){
			magh = (K - A * i) / B;
			ans += CHOOSE(n, i) * CHOOSE(n, magh);
			ans %= MOD;
		}
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


