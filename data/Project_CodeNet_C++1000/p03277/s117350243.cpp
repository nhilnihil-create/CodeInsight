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
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};//RDLU
ll n;
vi q;
class BIT{
	public:
	//[1,i]
	int n;
	vi bit;
//	int bit[MAZ_N+1];
	BIT(int size){
		n=size;
		bit=vi(n+1);
	}
	Def query(int i){//sum
		Def s=0;
		while(i>0){
			s+=bit[i];
			i-=i&-i;
		}
		return s;
	}
	void add(int i,Def x){
		while(i<=n){
			bit[i]+=x;
			i+=i&-i;
		}
	}
};
ll f(int a){
	vp in(n+1);
	rep(i,n+1)in[i].second=i;
	rep(i,n)if(q[i]>=a)in[i+1].first=1;
	else in[i+1].first=-1;
	
	rep(i,n)in[i+1].first+=in[i].first;
	sort(all(in));
	ll co=0;
	BIT bit(n+1);
	rep(i,n+1){
		co+=bit.query(in[i].second+1);
		bit.add(in[i].second+1,1);
	}
	// cout<<a<<" "<<co<<endl;
	// rep(i,n+1)cout<<in[i].first<<" "<<in[i].second<<endl;
	return co;
}
int main(){
	cin>>n;
	q=vi(n);
	rep(i,n)cin>>q[i];
	if(n==1){
		cout<<q[0]<<endl;
		return 0;
	}
	
	int l=0,r=1000000010;
	while(r-l>1){
		int h=(l+r)/2;
//		cout<<h<<" "<<f(h)<<endl;
		if(f(h)>=n*(n+1)/2/2)l=h;
		else r=h;
	}

	cout<<l<<endl;
	
}




