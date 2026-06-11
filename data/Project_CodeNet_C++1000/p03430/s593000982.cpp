#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll,ll> Pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define repp(i, n) for(int i=1;i<=n;i++)
#define all(x) x.begin(), x.end()

#define geti1(X) scanf("%d",&X)
#define geti2(X,Y) scanf("%d%d",&X,&Y)
#define geti3(X,Y,Z) scanf("%d%d%d",&X,&Y,&Z)
#define geti4(X,Y,Z,W) scanf("%d%d%d%d",&X,&Y,&Z,&W)

#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define geti(...) GET_MACRO(__VA_ARGS__, geti4, geti3, geti2, geti1) (__VA_ARGS__)

#define INF 7654321
#define IINF 87654321987654321LL
#define MAXV 200500

ll mod = 1e9 + 7;


int dp[301][301][301];
string s;
int N,K;

int solve(int l, int r, int k){

	if( l == r ) return 1;
	if( l > r ) return 0;

	int& res = dp[l][r][k];
	if( res != -1 ) return res;
	res = 0;
	if( s[l] == s[r] ){
		res = max(res, 2 + solve(l+1,r-1,k) );
	}
	else{
		if( k > 0 ){
			res = max(res, 2 + solve(l+1,r-1,k-1) );
		}
		res = max(res, solve(l+1,r,k) );
		res = max(res, solve(l,r-1,k) );
	}


	return res;
}	

int main(){
	memset(dp,-1,sizeof dp);
	cin >> s >> K;
	N = sz(s);

	cout << solve(0,N-1,K);

}