#include<bits/stdc++.h>
#include"unistd.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int mod_pow(int x,int y,int m=mod){
	int res=1;
	while(y>0){
		if(y&1)(res*=x)%=m;
		(x*=x)%=m;
		y>>=1;
	}
	return res;
}
int N,A[100005];
int perm[100005];
void calc(){
	perm[1]=1;
	REP(i,N+1)(perm[1]*=i)%=mod;
	for(int i=2;i<=N;i++)perm[i]=perm[1]*mod_pow(i,mod-2)%mod;
	REP(i,N+1)(perm[i+1]+=perm[i])%=mod;
}
signed main(){
	cin>>N;
	calc();
	int ans=0;
	rep(i,N){
		int a;cin>>a;
		int memo=(perm[i+1]-perm[1]+mod)%mod;
		int memo2=(perm[N-i]-perm[1]+mod)%mod;
		ans+=a*(memo+memo2+perm[1])%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
}
