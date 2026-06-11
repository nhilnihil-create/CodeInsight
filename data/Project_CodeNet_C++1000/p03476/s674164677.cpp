#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

long long modpow(long long n,long long p,long long mod);

int main(){
	long long q;
	cin>>q;
	vector<bool> sosu(inf/1000,true);
	sosu.at(0)=false;
	sosu.at(1)=false;
	vector<long long> ruiseki(inf/1000,0);

	for(long long i=0;i<inf/1000;i++){
		if(sosu.at(i)){
			for(long long j=i*2;j<inf/1000;j+=i){
				sosu.at(j)=false;
			}
		}

		if(i==0) continue;
		ruiseki.at(i)=ruiseki.at(i-1);
		if(sosu.at(i) && sosu.at((i+1)/2)){
			ruiseki.at(i)++;
		}
	}

	for(long long i=0;i<q;i++){
		long long l,r;
		cin>>l>>r;
		cout<<ruiseki.at(r)-ruiseki.at(l-1)<<endl;
	}

	return 0;
}

long long modpow(long long n,long long p,long long mod){
	if(p==0) return 1;
	if(p%2==0) return (modpow(n,p/2,mod)*modpow(n,p/2,mod))%mod;
	if(p%2==1) return (modpow(n,p-1,mod)*n)%mod;
	cerr<<"ERROR"<<endl;
	return 1;
}
