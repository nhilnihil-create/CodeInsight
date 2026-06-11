// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define FOR(i,a) for(auto i:a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) {rep(_,v.size())cout<<" "<<v[_];puts("");}
#define show2d(v) {rep(__,v.size())show1d(v[__]);}
using namespace std;
//kaewasuretyuui
typedef long long ll;
#define int ll
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
#define mt make_tuple
typedef tuple<int,int,int,int> tp;
typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
// int dx[]={0,1,0,-1};
// int dy[]={1,0,-1,0};//RDLU
#define yes puts("YES")
#define no puts("NO")

int dp[10010][110][2];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	vvi in(n,vi(3));
	rep(i,n)rep(j,3)cin>>in[i][j];

	sort(all(in),[](vi a,vi b){
		return a[0]+a[1]<b[0]+b[1];
	});
	vi dp(30000,-inf);
	dp[0]=0;
	rep(i,n)for(int j=in[i][1];j>=0;j--)if(dp[j]+inf)
		cmax(dp[j+in[i][0]],dp[j]+in[i][2]);
	int out=0;
	rep(i,30000)cmax(out,dp[i]);
	cout<<out<<endl;
}
