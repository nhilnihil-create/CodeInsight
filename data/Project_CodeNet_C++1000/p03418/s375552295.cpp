#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int MR=1e6+10;
typedef long long LL;

LL S(LL N, LL r)
{
	LL cap=N-r;
	LL b=r+1;
	LL m=cap/b;
	LL ans=0;
	while(m>0 && cap/m<N){
		ans+=(cap/m-b+1)*m;
		b=cap/m+1;
		m=cap/b;
	}
	ans+=(N-b+1)*m;
	ans+=N-r;
	return ans;
}

int main() {
	LL N,K,ans=0;
	cin>>N>>K;
	if(K==0){
		cout<<N*N<<endl;
		return 0;
	}
	for(LL r=K;r<N;r++){
		ans+=S(N,r);
		//printf("r=%lld %lld\n",r,S(N,r));
	}
	cout<<ans<<endl;
    return 0;
}