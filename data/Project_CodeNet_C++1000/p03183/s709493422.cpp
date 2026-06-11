#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<functional>
#include<utility>
#include<algorithm>
#include<sstream>
#include<cstring>
#include<cmath>
#include<cctype>
#include<exception>
#include<climits>
#include<cfloat>
#include<iomanip>
#include<bitset>
#include<streambuf>
#include<cstdlib>
#include<ctime>
//#include"functions.h"
//#include"highprecision.h"
#define pb push_back
#define pf push_front
#define ppb pop_back
#define mp make_pair
#define np next_permutation
#define fi first
#define sc second
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pff pair<float,float>
#define pdd pair<double,double>
#define psi pair<string,int>
#define pis pair<int,string>
#define ppi pair<pii,int>
#define pdi pair<pii,pii>
#define LN 84757
#define INF 1e9
#define LLINF 1e18
#define MAXINT 0x7ffffffe
#define MAXLL 0x7fffffffffffffff
#define EPS 1e-5
#define DEPS 1e-9
#define LDEPS 1e-13
#define MOD 1000000007
#define E 2.7182818284
#define PI 3.1415926535
#define rep(a,b) for(int a=0;a<b;a++)
#define forn(a,n) for(int a=1;a<=n;a++)
#define forr(a,n) for(int a=n;a>=1;a--)
#define repn(a,n,p) for(int a=0;a<n;a+=p)
#define repr(a,n) for(int a=n-1;a>=0;a--)
#define foreach(a,b) for(__typeof(b.begin())a=b.begin();a!=b.end();a++)
#define fillemp(a) memset(a,0,sizeof(a))
#define fillinf(a) memset(a,0x3f,sizeof(a))
#define frestream freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define stdf(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout);
#define inputf(a) freopen(a,"r",stdin);
#define outputf(a) freopen(a,"w",stdout);
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define mod 1000000007
typedef long long ll;
typedef long double dl;
using namespace std;
#define int long long
int n;
int dp[1010][40010],w[1010],s[1010],v[1010];
struct block{
	int w,s,v;
};
block a[1010];
inline void chkmax(int& a,int b){
	a=max(a,b);
}
inline void fread(int& n){
	int res=0;bool f=0;
	char ch=getchar();
	if(ch=='-'){
		f=1;
	}
	else{
		res=ch-'0';
	}
	while(1){
		ch=getchar();
		if(ch==' '||ch=='\n'){
			n=f?-res:res;
			return;
		}
		res*=10;
		res+=(ch-'0');
	}
	n=res;
}
inline bool cmp(block x,block y){
	return x.s+x.w<y.s+y.w;
}
//dp[i][j]=max{dp[i-1][j],dp[i-1][j-w[i]]+v[i](s[i]>=j-w[i])};
signed main(void){
	cin>>n;
	forn(i,n){
		cin>>a[i].w>>a[i].s>>a[i].v;
	}
	sort(a+1,a+n+1,cmp);
	forn(i,n){
		w[i]=a[i].w;
		s[i]=a[i].s;
		v[i]=a[i].v;
	}
	forn(i,n){
		rep(j,40010){
			chkmax(dp[i][j],dp[i-1][j]);
			if(s[i]>=j-w[i]&&j-w[i]>=0){
				chkmax(dp[i][j],dp[i-1][j-w[i]]+v[i]);
			}
		}
	}
	int ans=0;
	forn(i,n){
		rep(j,40010){
			chkmax(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}