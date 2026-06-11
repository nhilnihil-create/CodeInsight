#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 100005

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unordered_map<int,int> umii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

mt19937 g1(time(0));

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int len,cnt;
ll dp[MAXN][3];
char s[MAXN];

int main(){
	scanf("%s",s+1); len = (int)strlen(s+1);
	for(int i=1; i<=len; i++){
		if(s[i] == '?'){
			dp[i][0] = (dp[i-1][0]*3+fpow(3,cnt,MOD))%MOD;
			dp[i][1] = (dp[i-1][1]*3+dp[i-1][0])%MOD;
			dp[i][2] = (dp[i-1][2]*3+dp[i-1][1])%MOD;
			cnt++;
		}else{
			for(int k=0; k<3; k++) dp[i][k] = dp[i-1][k];
			if(s[i] == 'A') dp[i][0] = (dp[i][0]+fpow(3,cnt,MOD))%MOD;
			else if(s[i] == 'B') dp[i][1] = (dp[i][1]+dp[i-1][0])%MOD;
			else dp[i][2] = (dp[i][2]+dp[i-1][1])%MOD;
		}
	}
	printf("%lld\n",dp[len][2]);
}
