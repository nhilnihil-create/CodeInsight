#include <bits/stdc++.h>

using namespace std;

#define DBG cerr << '!' << endl;
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)
#define INF 1000000000

typedef long long ll;
typedef pair<ll,ll> P;

int dp[303][303][303];
string s;
int k;

int dfs(int K,int L,int R)
{
//	cout << K << ' ' << L << ' ' << R << endl;
	if(K < 0)return -100000000;
	if(L > R)return 0;
	if(dp[K][L][R] != 0)return dp[K][L][R];
	int ret = 0;
	if(s[L] == s[R])ret = max(ret,dfs(K,L+1,R-1)+2);
	else ret = max(ret,dfs(K-1,L+1,R-1)+2);
	ret = max(ret,dfs(K,L+1,R));
	ret = max(ret,dfs(K,L,R-1));
	
	return dp[K][L][R] = ret;
}


int main()
{
	cin >> s >> k;
	
	REP(K,303)REP(i,303)dp[K][i][i] = 1;
	cout << dfs(k,0,s.size()-1) << endl;
	
	return 0;
}
