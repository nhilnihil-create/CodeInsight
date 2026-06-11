#include <bits/stdc++.h>
using namespace std;
 
#define vi vector<int>
#define ll long long
#define ld long double
#define vvi vector<vi>
#define vll vector<ll>
#define vld vector<ld>
#define vvll vector<vll>
#define vvld vector<vld>
#define MOD 1000000007
#define endL << '\n'
#define ii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define endL << '\n'
#define vii vector<ii>
#define pb push_back

/*
ll powmod(ll x, ll y, ll mod){
	ll res = 1;
	while (y > 0){
		if (y%2) res = (res*x) % mod;
		x = (x*x) % mod;
		y /= 2;
	}
	return res;
}
*/

/*const int N = 1000000;
int lp[N+1];
vector<ll> pr;

void sieve(){
	for (int i=2; i<=N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}*/
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1; //cin >> t;
	while(t--){
		cin >> n;
		int x;
		vector<int> par(3, 0);
		for (int i = 0; i < n; i++){
			cin >> x; par[x-1]++;
		}
		/*int nax = 305;
		double dp[n][305][305];*/
		vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(305, vector<double>(305, 0.0)));
		// cout << par[0] << " " << par[1] << " " << par[2] << endl;
		for (int filled = 1; filled <= n; filled++){
			for (int i = filled; i >= 0; i--){
				for (int j = par[1]+par[2]; j >= 0; j--){
					int k = filled - i - j;
					// cout << i << " " << j << " " << k << endl;
					if (k < 0 || k > par[2]) continue;
					// cout << "Correct: " << i << " " << j << " " << k << endl;
					dp[i][j][k] = 1.0;
					double res = ((i == 0) ? 0 : (i * dp[i-1][j][k]));
					res += ((j == 0) ? 0 : (j * dp[i+1][j-1][k]));
					res += ((k == 0) ? 0 : (k * dp[i][j+1][k-1]));
					res *= (1.0)/n;
					dp[i][j][k] += res;
					dp[i][j][k] *= (1.0 * n) / filled;
				}
			}
		}
		cout << fixed << setprecision(10) <<  dp[par[0]][par[1]][par[2]];


	}
}
