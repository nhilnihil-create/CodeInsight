#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define si(x) x.size()

ll N;
ll PP[200005];
ll RP[200005];
ll f[200005];
ll dp[200005];
ll ans=INF;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;
rep(i,N){
	ll p,k; 
	cin>>p;
	k=N-p+1;
	PP[p]=i;
	RP[k]=N-1-i;
}
rep1(k,N+1){
	if(RP[k-1]<RP[k]) dp[k]=dp[k-1];
	else dp[k]=k-1;
}
rep(i,N+1){
	f[i]=i+dp[N-i];
	if(i>0&&PP[i]==0) f[i]--;
}
rep(i,N+1){
	ans=min(ans,f[i]);
}
cout<<ans<<endl;

}
	