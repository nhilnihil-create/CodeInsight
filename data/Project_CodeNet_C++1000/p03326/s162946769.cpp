#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define f first
#define s second

ll N,M;
ll x[1005],y[1005],z[1005];
ll xyz[10][1005];
ll s[10];
ll ans;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>M;

rep(i,N){
	cin>>x[i]>>y[i]>>z[i];

	xyz[0][i]=x[i]+y[i]+z[i];
	xyz[1][i]=x[i]+y[i]-z[i];
	xyz[2][i]=x[i]-y[i]+z[i];
	xyz[3][i]=-x[i]+y[i]+z[i];
	xyz[4][i]=x[i]-y[i]-z[i];
	xyz[5][i]=-x[i]-y[i]+z[i];
	xyz[6][i]=-x[i]+y[i]-z[i];
	xyz[7][i]=-x[i]-y[i]-z[i];
}

rep(i,8){
	sort(xyz[i],xyz[i]+N,greater<ll>());
}

rep(i,8){
	rep(j,M){
		s[i]+=xyz[i][j];
	}
}

rep(i,8){
	ans=max(ans,s[i]);
}

cout<<ans<<endl;


}
	
