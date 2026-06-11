#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(n);++i)
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

int main(){//Refering other editorials.
	int d,g;
	cin>>d>>g;
	
	vi p(d),c(d);
	REP(i,d) cin>>p[i]>>c[i];
	
	int ans=INF;
	REP(mask,(1<<d)){//p[i]点問題を全部選ぶ.
		int score=0,tmp=0,np=-1;//合計スコア, 問題数, 選ばなかった問題で最大点スコアの問題.
		REP(i,d){
			if((mask>>i)&1){
				score+=100*(i+1)*p[i]+c[i];
				tmp+=p[i];
			}else np=i;
		}
		
		if(score<g){//足りない場合.
			int hoge=100*(np+1);
			int need=(g-score+(hoge-1))/hoge;
			if(need>=p[np]) continue;//REP(mask).
			tmp+=need;
		}
		
		ans=min(ans,tmp);
	}
	
	cout<<ans<<endl;
}