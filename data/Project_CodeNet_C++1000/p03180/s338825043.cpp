#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 10000000000007LL
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
template<typename T1,typename T2>
T1 amin(T1 &a,T2 b)
{
	a=min(a,b);
	return a;
}
template<typename T1,typename T2>
T1 amax(T1 &a,T2 b)
{
	a=max(a,b);
	return a;
}


int n;
int a[18][18];
int val[1<<16];
int dp[1<<16];

int calc(int mask){
	int &ans=dp[mask];
	if(ans!=-1)return ans;
	for (int s=mask; s; s=(s-1)&mask){
		ans=max(ans,calc(mask^s)+val[s]);
	}
	return ans;
}
void solve(){
	mem1(dp);
	cin>>n;
	rep(i,0,n)rep(j,0,n)cin>>a[i][j];
	dp[0]=0;
	rep(i,0,1<<n){
		rep(j,0,n){
			rep(k,j+1,n){
				if(((1<<j)&i)&&((1<<k)&i))val[i]+=a[j][k];
			}
		}
	}
	cout<<calc((1<<n)-1);
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
