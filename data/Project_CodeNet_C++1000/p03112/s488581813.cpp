#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll A,B,Query;
ll s[100005],t[100005];
//左0右1
ll dfs(bool LR,bool AB,ll now,ll n){
	ll ret=0;
	if(AB){
		ll to;
		ll in=lower_bound(s,s+A,now)-s; 
		if(!LR){
			if(now>s[A-1]){
				to=s[A-1];
			}else{
				to=s[in];
			}
		}else{
			if(now<=s[0]){
				to=s[0];
			}else{
				to=s[in-1];
			}
		}
		ret+=abs(to-now);
		if(n==1) return ret;
		ret+=min(dfs(0,0,to,n+1),dfs(1,0,to,n+1));
	}else{
		ll to;
		ll in=lower_bound(t,t+B,now)-t;
		if(!LR){
			if(now>t[B-1]){
				to=t[B-1];
			}else{
				to=t[in];
			}
		}else{
			if(now<=t[0]){
				to=t[0];
			}else{
				to=t[in-1];
			}
		}
		ret+=abs(to-now);
		if(n==1) return ret;
		ret+=min(dfs(0,1,to,n+1),dfs(1,1,to,n+1));
	}
	return ret;
}
int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>A>>B>>Query;
rep(i,A) cin>>s[i];
rep(i,B) cin>>t[i];
rep(i,Query){
ll x; cin>>x;
ll d1=0;
ll d2=0;
//神社firstならtrue
d1=min(dfs(0,1,x,0),dfs(1,1,x,0));
//寺firstならfalse
d2=min(dfs(0,0,x,0),dfs(1,0,x,0));
cout<<min(d1,d2)<<endl;

}

}
    
