#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;

ll dp[11][1011];
ll p[111], c[111];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,m; cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> p[i] >> c[i];
		c[i]/=100;
	}
	m/=100;
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0LL;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=1000; j++){
			if(dp[i-1][j]!=-1){
				for(int k=0; k<p[i]; k++)
					dp[i][j+k]=max(dp[i][j+k],dp[i-1][j]+k*i);
				dp[i][j+p[i]]=max(dp[i][j+p[i]],dp[i-1][j]+p[i]*i+c[i]);
			}
		}
	}
	for(int j=0; j<=1000; j++){
		if(dp[n][j]>=m){
			cout << j << endl;
			return 0;
		}
	}
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
