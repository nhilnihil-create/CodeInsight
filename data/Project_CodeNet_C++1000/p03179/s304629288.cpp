#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll mod = 1e9+7;
const int maxn = 3000+1;
ll dp[maxn][maxn];
string str;
int N;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> str;
	dp[0][1] = 1;
	forn(i,2,N+1){
		dp[0][i] += dp[0][i-1];
		dp[0][i] %= mod;
	}
	forn(i,1,N){
		for(int j = 1; j <= i+1; j++){
			if(str[i-1] == '<'){
				dp[i][j] = dp[i-1][j-1];
				//forn(k,1,j){
					//dp[i][j] += dp[i-1][k];
					//dp[i][j] %= mod;
				//}
			}else{
				dp[i][j] = ((dp[i-1][i+1]%mod)-(dp[i-1][j-1]%mod))%mod;
				
				//forn(k,j,i+2){
					//dp[i][j] += dp[i-1][k];
					//dp[i][j] %= mod;
				//}
			}
			//cout << i << ' ' << j << ' ' << dp[i][j] << ":D\n";
		}
		for(int j = 1; j <= N; j++){
			dp[i][j] = ((dp[i][j])+(dp[i][j-1]))%mod;
			dp[i][j] %= mod;
		}
	}
	ll res = dp[N-1][N];
	if(res < 0)res += mod;
	cout << res << '\n';
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
