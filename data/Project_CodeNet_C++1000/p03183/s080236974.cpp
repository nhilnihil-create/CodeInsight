#include <ext/pb_ds/assoc_container.hpp> 	// Common file
#include <ext/pb_ds/tree_policy.hpp> 		// Including tree_order_statistics_node_update
#include<bits/stdc++.h>
#define int            		long long
#define x              		first
#define y              		second
#define all(aaa)       		(aaa).begin(),(aaa).end()
#define REP(i,sss,eee) 		for(int i=sss;i<=eee;++i)
#define pb             		push_back
#define pii            		pair<int,int>
#define vi             		vector<int>
#define speed          		ios_base::sync_with_stdio(0);cin.tie(0);
#define N              		1000000007
using namespace __gnu_pbds;
using namespace std;
template <class T>
T MAX(T a, T b){return ((a>b)?a:b);}
template <class T>
T MIN(T a, T b){return ((a<b)?a:b);}
template <class T>
T MOD(T a){return ((a>=0)?a:(-1*a));}
template <class T>
void SWAP(T &a,T &b){T temp=a;a=b;b=temp;}

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

long long ex(long long a, long long b){
	if(b==0||a==1){return 1;}
	if(a==0||b==1){return a;}
	long long tmp=ex(a,(b/2));
	if(b%2){return ((((tmp*tmp)%N)*a)%N);}
	else{return ((tmp*tmp)%N);}
}
long long inv(long long k){
	if(k==1){return 1;}
	else{return ex(k,N-2);}
}
/*****************default********************/
int inf=1000000000000000;
std::vector<int> w,s,v;
struct nod
{
	int wt;int so;int va;
};
bool cmp(nod & n1, nod & n2)
{
	return ((n1.so-n2.wt)<(n2.so-n1.wt));
}
int pre=0;
std::vector<std::vector<int>> dp;
int f(int ix, int rem)
{
	if(ix==0){return 0;}
	if(rem==inf)
	{
		return MAX((v[ix]+dp[ix-1][s[ix]]),f(ix-1,inf));
	}
	int poss1=0;
	if((rem-w[ix])>=0){poss1=(v[ix]+dp[ix-1][MIN((rem-w[ix]),s[ix])]);}
	dp[ix][rem]=MAX(poss1,dp[ix-1][rem]);
	return dp[ix][rem];
}
int solve()
{
	int n;cin>>n;
	w.pb(0);s.pb(0);v.pb(0);
	std::vector<nod> inp(n);
	REP(i,0,n-1)
	{
		cin>>(inp[i].wt)>>(inp[i].so)>>(inp[i].va);
	}
	sort(inp.begin(),inp.end(),cmp);
	dp.resize(n+1,std::vector<int>(10005,0));
	for(auto it:inp){w.pb(it.wt);s.pb(it.so);v.pb(it.va);}
	REP(i,1,n)
	{
		REP(j,0,10002)
		{
			f(i,j);
		}
		f(i,inf);
	}
	cout<<f(n,inf)<<"\n";
}
signed main(){
	//speed
	int tt=1;
	//cin>>tt;
	while(tt--)
	{
		solve();
	}
	return 0;
}