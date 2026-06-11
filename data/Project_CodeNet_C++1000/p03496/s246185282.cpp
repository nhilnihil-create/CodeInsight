// g++ macro.cpp -std=c++14
#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
 
#define dump(x)  cout << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl
#define possible(n) cout << ((n) ? "possible" : "impossible"  ) << endl
 
#define SANKOU(n,a,b) cout << ((n) ? (#a) : (#b) ) << endl
 
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) for(ll i=0;i<(n);++i)
#define REPR(i,n) for(ll i=n;i>=0;i--)
 
#define FOREACH(x,a) for(auto& (x) : (a) )
 
#define WFA(d,v) REP(k,v)REP(i,v)REP(j,v)d[i][j]=min(d[i][j],d[i][k]+d[k][j])
 
#define SCOUT(x) cout<<(x)<<" "
#define ENDL cout<<endl
 
#define VECCIN(x) for(auto&youso_: (x) )cin>>youso_
#define VECIN2(x,y) REP(i,x.size())cin>>x[i]>>y[i]
#define VECCOUT(x) if(1){for(auto tt=x.begin();tt!=x.end();tt++){if(tt!=x.begin())cout<<" ";cout<<(*tt);}cout<<endl;}
 
#define ALL(obj) (obj).begin(),(obj).end()
 
#define EXIST(n,x) (find(ALL(n),x)!=n.end())
#define UNIQUE(obj) sort(ALL( obj )); obj.erase(unique(ALL(obj)),obj.end())
#define EN(x) if(1){cout<<#x<<endl;return 0;}
#define COUT(x) cout<<(x)<<endl
void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail){
    cin>>head;
    CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)
 
template <class T = ll>
T IN(){T x;cin>>x;return (x);}
 
template <class Head>
void VT(Head head){}
template <class Head,class Seco,class... Tail>
void VT(Head&& head,Seco&& seco,Tail&&... tail){
    seco.resize(head);
    VT(head,move(tail)...);
}
void VT2(){}
template <class Head,class... Tail>
void VT2(Head&& head,Tail&&... tail){
  VECCIN(head);
  VT2(move(tail)...);
}
 
template <class Head>
void VT3(Head&& head){}
template <class Head,class Seco,class... Tail>
void VT3(Head&& head,Seco&& seco,Tail&&... tail){
  seco[head]=IN();
  VT3(head,move(tail)...);
}
 
#define VC1(n,...) V __VA_ARGS__;VT(n,__VA_ARGS__);VT2(__VA_ARGS__); //aaabbbccc
#define VC2(n,...) V __VA_ARGS__;VT(n,__VA_ARGS__);REP(i,n)VT3(i,__VA_ARGS__); //abcabcabc
 
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision; // cpp_int
 
#define P pair<ll,ll>
#define V vector<ll>
#define M map<ll,ll>
#define S set<ll>
 
#define pb(a) push_back(a)
#define mp make_pair

int main(){
	CIN(n);
	VC1(n,a);
	// 全て0なら例外処理でおわり
	// 0,0,0,1のような状態を考える
	// 1,0,0,1 1,0,0,2 1,2,0,2 1,2,0,4 のようにして2N-2回ぐらいでできそう
	// -2,5,1 -> -2,5,6 -> 4,5,6 -> 4,5,12 -> 4,17,12 -> 4,17,24
	
	if(!(*max_element(ALL(a)) - *min_element(ALL(a))))
		EN(0);

	int maxel=0;
	int maxind=0;
	REP(i,n)
		if(abs(a[i])>maxel){
			maxel = abs(a[i]);
			maxind = i;
		}
	bool ismin = a[maxind] < 0;
	if(ismin){
		COUT(2*n);
		SCOUT(maxind+1);
		COUT(1);
		SCOUT(1);
		COUT(1);
		REP(i,n-1)
			cout << 1 << " " << n - i << "\n" << 1 << " " << 1 << "\n";
	}else{
		COUT(2*n);
		SCOUT(maxind+1);
		COUT(n);
		SCOUT(n);
		COUT(n);
		REP(i,n-1)
			cout << n << " " << i + 1 << "\n" << n << " " << n << "\n";
	}

	return 0;
}
