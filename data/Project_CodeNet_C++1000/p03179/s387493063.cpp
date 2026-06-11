#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;

#define rep(i,n)	for(ll i=0;i<(n);i++)
#define SZ(x) ((ll)x.size())
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define F first
#define S second
#define int ll
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// const ll MOD = INT_MAX;
const double PI = acos(-1);

void openfile(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
}

const int N = 3005;
const int mod = 1e9+7;
char s[N];
int dp[N][N];
// dp(i,j) - the number of ways to put numbers in prefix of size 'i'
// such that the last number is j

void add(int &a,int b){
	a += b;
	if(a >= mod)	a -= mod;
}

signed main(){
	IOS
	int n;
	scanf("%lld", &n);
	scanf("%s", s);
	dp[1][1] = 1;
	for(int len = 2; len <= n; len++){
		for(int a = 1; a <= len; a++)	add(dp[len-1][a],dp[len-1][a-1]);	// compute prefix sums
		for(int b = 1; b <= len; b++){
			int L, R;
			if(s[len-2] == '<')	L = 1, R = b - 1;
			else				L = b, R = len - 1;

			// for(int i = L; i <= R; i++)	add(dp[len][b], dp[len-1][i]);	// prefix sum
			if(L <= R)	add(dp[len][b], (dp[len-1][R] - dp[len-1][L-1] + mod) % mod);

			// for(int a = 1; a <= len - 1; a++){
			// 	// previous pos
			// 	int real_a = a;
			// 	if(a >= b)	real_a++;
			// 	assert(real_a != b);
			// 	if((real_a < b) != (s[len-2] == '<'))	continue;
			// 	add(dp[len][b],dp[len-1][a]);
			// }
		}
	}
	int ans = 0;
	rep(i,n)	add(ans, dp[n][i+1]);
	printf("%lld\n", ans);
}
