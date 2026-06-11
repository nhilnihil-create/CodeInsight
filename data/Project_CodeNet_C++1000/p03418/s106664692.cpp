#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int N,K; cin>>N>>K;
	int ans=0;
	if(K==0)ans=N*N;
	else{
		int p,r;
		for(int b=1;b<=N;b++){
			r=N%b; p=(N-r)/b;
			ans+=p*max(0LL,b-K)+max(0LL,r-K+1);
		}
	}
	cout<<ans<<endl;
}