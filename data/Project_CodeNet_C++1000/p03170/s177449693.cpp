#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fp(i,a,b) for(int i=a ; i<b ; i++)
#define fn(i,a,b) for(int i=a ; i>=b ; i--)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int M=1e5+5;
const ll INF=1e15;
const int MOD=1e9+7;

int n,k;
int dp[M],val[105];

int DP(int x){
	if (x < 0) return 1;
	if (dp[x] != -1) return dp[x];
	dp[x] = 1;
	fp(i,0,n) dp[x] = dp[x]&DP(x-val[i]);
	dp[x] = dp[x]^1;
	return dp[x];
}

int main(){

	fastio;
	cin >> n >> k;
	fp(i,0,M) dp[i] = -1;
	fp(i,0,n) cin >> val[i];
	if (DP(k) == 1) cout << "First\n";
	else cout << "Second\n";

	return 0;
}
