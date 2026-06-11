#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	string s; cin>>s;
	int N=(int)s.size();
	int A[N+1],C[N+1]; A[0]=0; C[N-1]=0;
	int cnt[N+1]; cnt[0]=0;
	rep(i,1,N+1){
		A[i]=A[i-1]+(s[i-1]=='A' ? 1 : 0);
		C[i]=C[i-1]+(s[i-1]=='C' ? 1 : 0);
		cnt[i]=cnt[i-1]+(s[i-1]=='?' ? 1 : 0);
	}
	long three[2*N]; three[0]=1;
	rep(i,1,2*N) three[i]=(3*three[i-1])%mod;
	long ans=0;
    long a,c;
	rep(i,0,N){
        if(s[i]=='A'||s[i]=='C') continue;
		if(cnt[i]==0) a=A[i];
        else a=three[cnt[i]-1] * (cnt[i]+3*A[i]) %mod;
        if(cnt[N]-cnt[i+1]==0) c=C[N]-C[i+1];
        else c=three[cnt[N]-cnt[i+1]-1] * (cnt[N]-cnt[i+1]+3*(C[N]-C[i+1])) %mod;
		(ans += a*c % mod)%=mod;
        //cout<<a*c % mod<<endl;
	}cout<<ans<<endl;
}