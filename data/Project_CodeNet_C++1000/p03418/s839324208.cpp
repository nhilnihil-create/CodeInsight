#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N,K;
ll ans;
int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>K;

if(K==0){
	cout<<N*N<<endl; return 0;
}

for(ll b=K+1; b<=N; b++){
	ll add1=(N/b)*(b-K);
	ll add2=N%b-(K-1);
	ans+=add1;
	if(N%b>=K) ans+=add2;
}

cout<<ans<<endl;



}
	
