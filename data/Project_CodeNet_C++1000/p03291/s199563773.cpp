#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define f first
#define s second

ll cnt[100005];
ll a[100005];
ll ab[100005];
ll abc[100005];
string S;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>S;

ll N=S.size();

if(S[0]=='A'||S[0]=='?') a[0]=1;

if(S[0]=='?') cnt[0]=3;
else cnt[0]=1;

rep1(i,N){
	if(S[i]=='A'){
		cnt[i]=cnt[i-1];
		a[i]=(a[i-1]+cnt[i-1])%mod;
		ab[i]=ab[i-1];
		abc[i]=abc[i-1];
	}
	if(S[i]=='B'){
		cnt[i]=cnt[i-1];
		a[i]=a[i-1];
		ab[i]=(ab[i-1]+a[i-1])%mod;
		abc[i]=abc[i-1];
	}
	if(S[i]=='C'){
		cnt[i]=cnt[i-1];
		a[i]=a[i-1];
		ab[i]=ab[i-1];
		abc[i]=(abc[i-1]+ab[i-1])%mod;
	}
	if(S[i]=='?'){
		cnt[i]=3*cnt[i-1]%mod;
		a[i]=(a[i-1]+cnt[i-1]+a[i-1]+a[i-1])%mod;
		ab[i]=(ab[i-1]+ab[i-1]+a[i-1]+ab[i-1])%mod;
		abc[i]=(abc[i-1]+abc[i-1]+abc[i-1]+ab[i-1])%mod;
	}
}

cout<<abc[N-1]<<endl;

}
	
