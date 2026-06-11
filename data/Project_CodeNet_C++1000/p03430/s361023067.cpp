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
str s;
ll K, n, dp[310][310][310];

int main(){
	IOS;
	cin >> s;
	cin >> K;
	ll n = s.size();
	if (n == 1) return cout << 1, 0;
	s = "." + s;
	//cout << n << '\n';
	for (int i = 1; i <= n; i++){
		dp[i][i + 1][0] = 1;
	}
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= n - i + 1; j++){
			for (int k = 0; k <= K; k++){
				if (k == 0){
					if (s[j] == s[j + i - 1]){
						dp[j][i + j][0] = dp[j + 1][i + j - 1][0] + 2;
					}
					dp[j][i + j][k] = max(dp[j][i + j][k], max(dp[j + 1][i + j][k], dp[j][i + j - 1][k]));
					
				}
				
				
				
				else if (k >= i - 1){
					dp[j][i + j][k] = i;
				}else{
					dp[j][i + j][k] = dp[j][i + j][k - 1];
					if (s[j] == s[i + j - 1]){
						dp[j][i + j][k] = dp[j + 1][i + j - 1][k] + 2;
					}
					dp[j][i + j][k] = max(dp[j][i + j][k], max(dp[j + 1][i + j][k], dp[j][i + j - 1][k]));
					dp[j][i + j][k] = max(dp[j][i + j][k], 2 + dp[j + 1][i + j - 1][k - 1]);
				}
				//cout << j << ' ' << j + i - 1 << ' ' << k << ' ' << dp[j][j + i][k] << '\n';	
			}
			
			
			
		}
		
		
	}
	cout << dp[1][n + 1][K];
	
	
	
	return 0;
}
