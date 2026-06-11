// Bismillaahirrahmaanirrahiim
/* Author	: Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define jehian using
#define mau namespace
#define libur std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

jehian mau libur;
/* MACROS FOR TYPE */
typedef long l;
typedef long double ld;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

/* MACROS FOR PRINT */
#define nl printf("\n");
#define sp printf(" ");

/* MACROS FOR FUNCTION AND METHOD */
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) for(int _je = sizeof(x)/sizeof(x[0]); _je--;) x[_je] = y

/* MACROS FOR ATTRIBUTE */
#define fi first
#define se second

/* MACROS FOR SCAN */
#define scc(x) scanf("%c", &x)
#define scd(x) scanf("%Lf", &x)
#define scf(x) scanf("%f", &x)
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scld(x) scanf("%Lf", &x)
#define scui(x) sci(x)
#define scul(x) scl(x)
#define scull(x) scll(x)

int dp[1<<26];
int now = 0;
int j;
int main(){
	string S;
	cin >> S;
	SET(dp,1e9);
	dp[0] = 0;
	for (ll i = 0; i < S.size(); ++i){
		now ^= (1 << (S[i] - 'a'));
		int MIN = 1e9;
		for (j = 1 << 25; j; j >>= 1){
			MIN = min(MIN, dp[now^j]);
		}
		dp[now] = min(dp[now], MIN+1);
	}
	cout << max(1, dp[now]) << endl;
	return 0;
}