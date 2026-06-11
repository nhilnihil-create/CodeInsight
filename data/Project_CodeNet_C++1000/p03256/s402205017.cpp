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
#define show1d(v) rep(i,v.size())cout<<" "<<v[i];cout<<endl<<endl;
#define show2d(v) rep(i,v.size()){rep(j,v[i].size())cout<<" "<<v[i][j];cout<<endl;}cout<<endl;
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
typedef ll Def;
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
typedef tuple<int,int,int> tp;
typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};//RDLU
/*
int main(){
	ll n,x;
	cin>>n>>x;
	vi in(n);
	rep(i,n)cin>>in[i];
	if(n>2001)return 0;
	ll out=inf;
	loop(i,1,n+1){
		ll sum=(n+i)*x;
		rep(j,i)sum+=in[n-1-j];
		for(int j=n-1;j>=0;j--){
			ll dis;
			if(j-i>=0)dis=in[j]-in[j-i];
			else dis=in[j];
			sum+=dis*((n-j-1)/i+2)*((n-j-1)/i+2);
		}
		out=min(out,sum);
	}
	
	cout<<out<<endl;
}
*/
int n,m;
string s;
vvi G,co;
vi used;
void dfs(int a){
	used[a]=0;
	rep(i,G[a].size()){
		int to=G[a][i];
		if(used[to]==0)continue;
		co[a]['A'!=s[to]]--;
		co[to]['A'!=s[a]]--;
	}
//	cout<<a<<endl;
//	show2d(co);
	rep(i,G[a].size()){
		int to=G[a][i];
		if(used[to]&&(co[to][0]==0||co[to][1]==0))
			dfs(to);
	}
}
int main(){
	cin>>n>>m>>s;
	G=vvi(n);
	used=vi(n,1);
	co=vvi(n,vi(2));
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].pb(b);
		G[b].pb(a);
		co[a]['A'!=s[b]]++;
		co[b]['A'!=s[a]]++;
	}
	rep(i,n)if(used[i]&&(co[i][0]==0||co[i][1]==0)){
		dfs(i);
	}
	
//	show2d(co);
//	show1d(used);
	
	bool h=false;
	rep(i,n)if(used[i])h=true;
	if(h)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}








