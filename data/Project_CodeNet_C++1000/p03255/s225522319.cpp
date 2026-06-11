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
#define show1d(v) rep(_,v.size())cout<<" "<<v[_];cout<<endl;
#define show2d(v) rep(_,v.size()){rep(__,v[_].size())cout<<" "<<v[_][__];cout<<endl;}cout<<endl;
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
// #define mt make_tuple
// typedef tuple<int,int,int> tp;
// typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 1e18+10 : 1e9+10;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};//RDLU
int main(){
	ll n,x;
	cin>>n>>x;
	vi in(n+1);
	rep(i,n)cin>>in[i+1];
	rep(i,n)in[i+1]+=in[i];
	ll out=inf;
	loop(i,1,n+1){
		ll sum=x*(n+i),co=1;
		for(ll j=n;j>=0;j-=i){
			ll t=co*2+1;
			if(co==1)t=5;
			sum+=(in[j]-in[max(0ll,j-i)])*t;
			if(sum>out)break;
			co++;
		}
		cmin(out,sum);
	}
	cout<<out<<endl;
}





