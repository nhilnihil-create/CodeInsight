#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<climits>

int main(){
	long long n, p;
	long long ans=1;
	long long tp;

	std::vector<bool> isPrime(1000001, true);
	std::vector<long long> prime;
	std::vector<long long> numPrime;

	std::cin>>n>>p;
	tp=p;

	isPrime[0]=false;
	isPrime[1]=false;

	for(long long i=2; i<1000001; i++){
		if(!isPrime[i])
			continue;

		prime.push_back(i);

		for(long long j=2*i; j< 1000001; j+=i){
			isPrime[j]=false;
		}
	}

	numPrime.resize(prime.size(), 0);

	for(long long i=0; i<prime.size(); i++){
		if(p==1)
			break;

		while(p%prime[i]==0){
			p/=prime[i];
			numPrime[i]++;
		}
	}
	
	for(long long i=0; i<prime.size(); i++){
		if(numPrime[i]<n)
			continue;

		long long tmp= numPrime[i]/n;
		ans*= std::pow(prime[i], tmp);		
	}

	if(n==1)
		ans=tp;

	std::cout<<ans<<std::endl;

	return 0;
}