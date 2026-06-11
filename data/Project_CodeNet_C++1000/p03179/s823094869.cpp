#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}

int dp[3005][3005];
void solve(){
	int n;
	string s;
	cin>>n>>s;
	dp[0][1]=1;
	
	rep(i,1,n){
		int r=i+1;
		rep(j,1,r+1){
			dp[i-1][j]+=dp[i-1][j-1];
			dp[i-1][j]%=M;
		}
		rep(j,1,r+1){
			if(s[i-1]=='>'){
				dp[i][j]=(M+dp[i-1][r-1]-dp[i-1][j-1])%M;
				// sigma(j,r-1);
			}
			else{
				dp[i][j]=(M+dp[i-1][j-1]-dp[i-1][0])%M;
				// sigma(1,j-1);
			}
		}
	}
	int ans=0;
	rep(i,0,3002)ans=(ans+dp[n-1][i])%M;
	cout<<ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}
