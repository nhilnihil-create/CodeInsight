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
const int mxn=1e5+5;
ll dp[mxn][4];
// 0 'A' 1 'B' 2 'C' 3, read "ABC" from left to right
void add(ll &a, ll b){
	a%=MOD; b%=MOD; a+=b; a%=MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	string s; cin >> s;
	memset(dp,0LL,sizeof(dp));
	dp[0][0]=1LL;
	int n=s.length();
	for(int i=0; i<n; i++){
		if(s[i]=='A'){
			for(int j=0; j<4; j++)add(dp[i+1][j],dp[i][j]);
			add(dp[i+1][1],dp[i][0]);
		}else if(s[i]=='B'){
			for(int j=0; j<4; j++)add(dp[i+1][j],dp[i][j]);
			add(dp[i+1][2],dp[i][1]);
		}else if(s[i]=='C'){
			for(int j=0; j<4; j++)add(dp[i+1][j],dp[i][j]);
			add(dp[i+1][3],dp[i][2]);
		}else{
			for(int j=0; j<4; j++){
				add(dp[i+1][j],3*dp[i][j]);
				if(j<3)add(dp[i+1][j+1],dp[i][j]);
			}
		}
	}
	cout << dp[n][3] << endl;
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
