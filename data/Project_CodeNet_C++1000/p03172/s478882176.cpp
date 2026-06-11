#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////
const int  MOD = 1e9+7;
int main()
{	int n , k;
	cin>>n>>k;
	vector <int> a(n),dp(k+1);
	for(auto &i:a)
		cin>>i;
	// base case intialization 
	dp[0] = 1;
	FOR(i,1,k)
	{
		dp[i] = 0;
	}
	// outer loop
	FOR(i, 0,n-1)
	{vector <ll> sum(k+1);
		sum[0] = dp[0];
		FOR(j ,1,k)
		sum[j] = (sum[j-1] + dp[j])%MOD;
		FOR(j,0,k)
		if(j<=a[i])
			dp[j] = sum[j];
		else
			{
				int s = j-a[i]-1;
				dp[j] = (sum[j]-sum[s]+MOD)%MOD;
			}
			sum.clear();
	}
	cout<<dp[k];
    return 0;
}