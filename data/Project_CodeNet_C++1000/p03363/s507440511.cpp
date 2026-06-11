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
ll ans;
ll A[200005];
ll S[200005];
ll cnt[200005];
map<ll,ll> MP;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;
rep(i,N) cin>>A[i];
S[0]=A[0];
rep1(i,N) S[i]=S[i-1]+A[i];
rep(i,N){
	cnt[i]=MP[S[i]];
	if(S[i]==0) cnt[i]++;
	MP[S[i]]++;
}
rep(i,N) ans+=cnt[i];
cout<<ans<<endl;

}
	