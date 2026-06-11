//実装が重そうな問題はある程度考えてから書く
//初期化を忘れずに（特に二分探索とか）
//コーナーケースを考えて（特に場合分けとか）
#include <bits/stdc++.h>
#define YES "YES"
#define NO "NO"
#define YESNO OUT(three(solve(),YES,NO))
#define ECHO OUT(solve())
#define three(A,B,C) ((A)?(B):(C))
#define FOR(i,a,b)  for(LL i=(a);i< (LL)(b);i++)
#define EFOR(i,a,b) for(LL i=(a);i<=(LL)(b);i++)
#define RFOR(i,a,b) for(LL i=(a);i>=(LL)(b);i--)
#define REP(i,b) FOR(i,zero,b)
#define EREP(i,b) EFOR(i,zero,b)
#define RREP(i,b) RFOR(i,b,zero)
#define ALL(c) c.begin(),c.end()
#define UNIQUE(c) sort(ALL(c));c.erase(unique(ALL(c)),c.end())
#define MAX(c) (*max_element(ALL(c)))
#define MIN(c) (*min_element(ALL(c)))
#define MP make_pair
#define FI first
#define SE second
#define SI(x) (LL(x.size()))
#define PB push_back
#define DEBUG(a) OUT(a)
#define DEBUG2(a,b) OUT2(a,b)
#define cat cout << __LINE__ << endl
#define OUT(a) cout << (a) << endl
#define OUT2(a,b) cout << (a) <<" "<<(b) << endl
#define int LL
#define zero 0LL
using namespace std;
template<typename T> inline void maximize(T &a,T b){a=max(a,b);}
template<typename T> inline void minimize(T &a,T b){a=min(a,b);}
template<typename T> inline bool middle(T a,T b,T c){return b<=a && a<=c;}
typedef long long LL;
typedef double ld;
typedef LL ut;
typedef vector<ut> VI;
typedef vector<VI> VII;
typedef pair<ut,ut> pr;
typedef pair<ut,pr> ppr;
typedef vector<pr> Vpr;
typedef vector<ppr> Vppr;
typedef priority_queue<pr,Vpr,greater<pr> > PQ;
inline void outputVI(VI x){REP(i,SI(x)){cout << three(i," ","") << x[i];}OUT("");}
const int SIZE1=1e6+1000;
const int SIZE2=2010;
const int SIZE3=400;
const int SIZE=SIZE1;
const LL p=7+1e9;
const LL INF=1LL<<60;
const long double EPS=1e-7;
string s;
ut N,M,K,X,L,Y,D;
bool able(int f,int c){
	return c>=f*(1+f);
}
int solve(int c,int a,int b){
	if(a>b) return 0;
	int s=a,e=b;
	while(s<=e){
		int f=(s+e)/2;
		if(able(f,c))
			s=f+1;
		else
			e=f-1;
	}
	return e-a+1;
}
signed main(){
	int Q;
	cin >> Q;
	int a,b;
	REP(i,Q){
		cin >> a >> b;
		if(a>b) swap(a,b);
		if(a>=b-1){
			cout << (a-1)*2 << endl;
			continue;
		}
		int ans=0;
		ans+=(a-1)*2;
		int ca=solve(a*b-1,a+1,b-1);
		ans+=ca*2+1;
		ca=a+1+ca;
		//cout << ca << endl;
		if(ca*ca< a*b) ans++;
		cout << ans << endl;
	}
	return 0;
}