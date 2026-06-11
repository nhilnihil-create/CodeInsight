#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(long long i=(a);((a)<(b)?i<=(b):i>=(b));((a)<(b)?++i:--i))
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

int main(){
	int n;
	cin>>n;
	
	vi x(n),y(n),h(n);
	REP(i,n) cin>>x[i]>>y[i]>>h[i];
	
	int yy,xx,hh;
	REP(i,n){
		if(h[i]>0){
			yy=y[i], xx=x[i], hh=h[i];
			break;
		}
	}
	
	FOR(cy,0,100)FOR(cx,0,100){//全探索.
		int ans=hh+abs(xx-cx)+abs(yy-cy);//ピラミッドの高さ.
		
		REP(i,n){
			bool jud=(max(ans-abs(x[i]-cx)-abs(y[i]-cy),0LL)==h[i]);//整合がとれてるか.
			if(!jud) goto Exit;
		}
		
		cout<<cx<<' '<<cy<<' '<<ans<<endl;
		return 0;
	
	Exit:
		continue;
	}
}