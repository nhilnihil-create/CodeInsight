// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
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
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
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
// #define mt make_tuple
//typedef tuple<pii,int,int> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-7;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
string s;int n;
int dp[301][301][301];
int f(int a,int b,int c){
	if(dp[a][b][c]!=-inf)return dp[a][b][c];
	if(b<=a)return 0;
	if(a+1==b)return 1;
	int out=0;
	if(s[a]==s[b-1]){
		out=max(out,2+f(a+1,b-1,c));
	}else if(c+1<=n){
		out=max(out,2+f(a+1,b-1,c+1));
	}
	out=max(out,f(a+1,b,c));
	out=max(out,f(a,b-1,c));
//	cout<<a<<" "<<b<<" "<<c<<" "<<out<<endl;
	return dp[a][b][c]=out;
}
int main(){
	cin>>s;
	cin>>n;
	rep(i,301)rep(j,301)rep(k,301)dp[i][j][k]=-inf;
	cout<<f(0,s.size(),0)<<endl;
//	cout<<min((int)s.size(),LCS(s,t)+2*m)<<endl;
}






