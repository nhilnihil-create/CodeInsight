#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(long long i=(a);((a)<(b)?i<=(b):i>=(b));((a)<(b)?++i:--i))
#define SZ(v)      ((int)(v).size())
#define ALL(v)     (v).begin(),(v).end()
#define debug(x)   cerr<<#x<<": "<<(x)<<endl
using namespace std;
using llong = long long;
using vi    = vector<int>;
using vvi   = vector<vi >;
using vvvi  = vector<vvi >;
using pii   = pair<int,int>;
constexpr int    INF=1e9;
constexpr double EPS=1e-9;
constexpr int    MOD=1e9+7;
template<class Type>
void line(const Type &a){int cnt=0;for(const auto &elem:a){cerr<<(cnt++?' ':'>');cerr<<elem;}cerr<<endl;}

/*繰り返し二乗法*/
template<typename T,typename U>
T ipow(T n,U k){//n^k. O(log K).
	if(k==0) return 1;
	T res=ipow(n*n,k/2);
	if(k&1) res*=n;
	return res;
}

int main(){//Refering other editorials.
	int n,m;
	cin>>n>>m;
	
	llong ans=(1800*m+100*n)*ipow(2,m);
	
	cout<<ans<<endl;
	return 0;
}