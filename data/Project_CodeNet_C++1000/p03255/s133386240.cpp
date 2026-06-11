#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=2e5;
const ll INF=1e18;
int N;
ll X,x[MAX_N];
ll psm[MAX_N+1];
int main(){
	cin>>N>>X;
	REP(i,N)cin>>x[i];
	psm[0]=0;
	REP(i,N){
		psm[i+1]=psm[i]+x[i];
	}
	ll ans=INF;
	FOR(k,1,N+1){
		ll tem=0;
		tem=(k+N)*X;
		int c=1;
		bool flg=true;
		for(int i=N-1;i>=0;i=max(i-k,-1)){
			ll v;
			if (c==1){
				v=5;
			}else{
				v=c*2+1;
			}
			if ((psm[i+1]-psm[max(0,i+1-k)])<(INF+v-1)/v){
				tem+=v*(psm[i+1]-psm[max(0,i+1-k)]);
				if (tem>=INF){
					flg=false;
					break;
				}
			}else{
				flg=false;
				break;
			}
			c++;
		}
		if (flg){
			ans=min(ans,tem);
		}
	}
	cout<<ans<<endl;
	return 0;
}