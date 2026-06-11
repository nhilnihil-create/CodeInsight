#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define endl '\n'
#define snd second
#define fst first
#define fastio cin.tie(NULL),cout.sync_with_stdio(true)

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair <ll,int> ii;
typedef pair <ii,int> iii;

const int mod = 1e9 + 7;
const ll INF = (1LL<<50);
const int N = 100005;

/*
	dp[i][j] : prob to have j heads among i tossed coins
*/

double dp[3005][3005];
int main(){
	fastio;
	int n;
	cin >> n;
	vector<double> p(n+1);
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){ // tosses
		for(int j = 0; j <= i; j++){ // heads
			dp[i][j] = (j > 0 ?(dp[i-1][j-1] * p[i]):0) + (dp[i-1][j] * (1-p[i]));
		}
	}
	double ans = 0;
	for(int i = n/2+1; i <= n; i++)
		ans += dp[n][i];
	cout << fixed << setprecision(10) << ans << '\n';
	return 0;
}
