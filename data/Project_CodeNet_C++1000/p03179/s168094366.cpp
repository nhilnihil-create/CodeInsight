#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

#define int long long

#ifdef lioraju
	#define ndbg(x) 
#else
	#define ndbg(x) x
#endif

const int mxsz = 3e3 + 5;
const int mod = 1e9 + 7;

string v;

int dp[mxsz][mxsz];
bool vis[mxsz][mxsz];

int d(int n, int k)
{
	if (k<0||k>n) return 0;
	if (!n) return 1;
	if (vis[n][k]) return dp[n][k];
	
	vis[n][k] = 1;
	int sum = v[n]=='<'? d(n, k-1): d(n, k+1);
	if (v[n-1]=='<') sum += d(n-1, k-1), sum %= mod;
	else sum += d(n-1, k), sum %= mod;
	
	return dp[n][k] = sum;
}

signed main()
{
	ndbg( ios::sync_with_stdio(0); cin.tie(0); );
	int n; cin>>n;
	cin>>v;
	
	v.push_back('<');
	cout<<d(n-1, n-1)<<'\n';
}