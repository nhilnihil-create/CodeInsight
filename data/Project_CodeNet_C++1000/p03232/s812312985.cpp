#include <bits/stdc++.h>
using namespace std;

const long long md=1e9+7;//mod
const int maxn=300100;
long long fac[maxn],inv[maxn];


long long powd(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1) res=res*x%md;
		x=x*x%md;
		y>>=1;
	}
	return res;
}

void csh(){
	fac[0]=1;
	for(int i=1;i<=1e5+30;i++)
		fac[i]=fac[i-1]*i%md;
	for(long long i=1;i<=1e5+30;i++)
    inv[i]=powd(i,md-2);
}

int main(){
  csh();
  long long N;
  cin >> N;
  vector<long long> A(N+1,0);
  for(auto i=1; i<=N; i++) cin >> A[i];
  long long ans=0;
  vector<long long> Psum(N+1,0);
  for (int i=1; i<=N; i++) Psum[i] = (Psum[i-1]+inv[i])%md;
  for (int i=1; i<=N; i++){
    ans += A[i]*(Psum[i]+Psum[N-i+1]+md-1)%md;
    ans %=md;
  }
  ans = (ans*fac[N])%md;
  cout << ans << endl;
}
