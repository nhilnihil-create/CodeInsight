/*

                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                    prayer
*/

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
#define loop(i,a,b) for(long long i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define FOR(i,a) for(auto i:a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) rep(_,v.size())cout<<" "<<v[_];cout<<endl;
#define show2d(v) rep(__,v.size()){rep(_,v[__].size())cout<<" "<<v[__][_];cout<<endl;}
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
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

vi t;
bool f(int a){
	map<int,int>ma;
	stack<int>len;
	rep(i,t.size()){
		int w=t[i];
		ma[w]++;
		while(!len.empty()&&len.top()>w){
			ma.erase(len.top());
			len.pop();
		}
		len.push(w);
		while(w>0&&ma[w]==a){
			ma.erase(w);
			len.pop();
			ma[--w]++;
			if(len.empty()||len.top()-w)len.push(w);
		}
		if(ma[0])return 0;
	}
	return 1;
}
signed main(){
	int n;
	cin>>n;
	vi in(n);
	rep(i,n)cin>>in[i];
	rep(i,n-1)if(in[i]>=in[i+1])t.pb(in[i+1]);
	if(t.size()==0){
		cout<<1<<endl;
		return 0;
	}
	int l=1,r=n;
	while(r-l>1){
		int h=(l+r)/2;
		if(f(h))r=h;
		else l=h;
	}
	cout<<r<<endl;
}
