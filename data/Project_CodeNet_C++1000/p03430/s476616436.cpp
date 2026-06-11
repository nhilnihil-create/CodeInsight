#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

ll dp[300][300][301];
string s;

ll memo(ll l, ll r, ll k) {
	if(dp[l][r][k]!=INF*INF) return dp[l][r][k];
	if(l==r) return dp[l][r][k]=1;
	if(l==r-1) {
		if(k>=1) return dp[l][r][k]=2;
		else if(s[l]==s[r]) return dp[l][r][k]=2;
		else return dp[l][r][k]=1;
	}
	ll ret=0;
	if(k>0) ret=memo(l+1,r-1,k-1)+2;
	if(s[l]==s[r]) ret=max(ret,memo(l+1,r-1,k)+2);
	ret=max(ret,max(memo(l+1,r,k),memo(l,r-1,k)));
	return dp[l][r][k]=ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll k;
	cin>>s>>k;
	ll n=(ll)s.size();
	REP(i,300) REP(j,300) REP(k,301) dp[i][j][k]=INF*INF;
	cout<<memo(0,n-1,k)<<endl;
}
