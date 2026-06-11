#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()

#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000

#define PB push_back
#define MP make_pair
#define F first
#define S second

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int main(){
	int d,g;
	cin >>d>>g;
	int y,x,ans=10000;
	vector<int>pp(d),p(d),c(d);
	REP(i,d) cin >>pp[i]>>c[i];
	REP(bit,1<<d){
		p=pp,x=0,y=0;
		REP(i,d){
			if(bit&(1<<i)){
				y+=p[i]*(i+1)*100+c[i];
				x+=p[i];
				p[i]=0;
			}
		}
		if(y<g){
			REPD(i,d){
				while(p[i]!=0){
					y+=(i+1)*100;
					p[i]--;
					x++;
					if(p[i]==0)y+=p[i]*(i+1)*100+c[i];
					if(y>=g)goto label;
				}
			}
		}
		label:
		chmin(ans,x);
	}
	cout<< ans<<endl;
}
