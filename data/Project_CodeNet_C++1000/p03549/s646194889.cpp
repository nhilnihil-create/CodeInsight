#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N,M;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>M;
ll time=1800*M+100*N;
ll ans=time*pow(2,M);
cout<<ans<<endl;

}
	
