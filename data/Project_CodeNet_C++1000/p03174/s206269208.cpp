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

const int M=22;
const ll INF=1e15;
const int MOD=1e9+7;

int n;
bool p[M][M];
ll dp[M][1<<M];

ll DP(int m,int c){
	ll &y=dp[m][c];
	if (m == n) return 1;
	if (y != -1) return y;
	y = 0;
	fp(i,0,n)
		if (p[m][i] && (c>>i)&1) y = (y + DP(m+1 , c & ( ~(1<<i) ))) % MOD;
	return y;
}

int main(){

	fastio;
	cin >> n;
	fp(i,0,n)
		fp(j,0,n) cin >> p[i][j];
	fp(i,0,n)
		fp(j,0,(1<<n)) dp[i][j] = -1;
	cout << DP(0,(1<<n)-1) << "\n";

	return 0;
}
