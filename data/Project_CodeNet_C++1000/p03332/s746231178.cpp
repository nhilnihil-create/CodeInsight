
#include <time.h>

#include <stdlib.h>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <numeric>

using namespace std;
#include <cstdint>
#include <iostream>
#include <utility>
#include <map>

int64_t gcd(int64_t a,int64_t b){//calc gcd
	if(a==0){
		return b;
	}else if(b==0){
		return a;
	}else if(a>b){
		return gcd(a%b,b);
	}else{
		return gcd(b%a,a);
	}
}
std::pair<int64_t,int64_t> extgcd(int64_t a,int64_t b){//a*(pair->first) + b*(pair->second) = gcd(a,b)
	if(a==0){
		return std::make_pair(0,1);
	}else if(b==0){
		return std::make_pair(1,0);
	}else{
		if(a>b){
			std::pair<int64_t,int64_t> d=extgcd(a%b,b);
			return std::make_pair(d.first,d.second-(a/b)*d.first);
		}else{
			std::pair<int64_t,int64_t> d=extgcd(a,b%a);
			return std::make_pair(d.first-(b/a)*d.second,d.second);
		}
	}

}
int64_t inline normalize_mod(int64_t a,int64_t m){
	return (m+a%m)%m;
}
int64_t mod_inv(int64_t a,int64_t m){//a^-1(mod m),m is a prime number
	int64_t raw=extgcd(a,m).first;
	return normalize_mod(raw,m);;
}
std::map<int64_t,int64_t> factorization(int64_t n){
	std::map<int64_t,int64_t> retval;
	for(int64_t i=2;i*i<=n;i++){
		int64_t counter=0;
		while(n%i==0){
			n=n/i;
			counter++;
		}
		if(counter!=0){
			retval.emplace(i,counter);
		}
	}
	return retval;
}
std::pair<int64_t,int64_t> mod_fact(int64_t n,int64_t m){//n!=first*m^second
	if(n==0){
		return std::make_pair(1,0);
	}else{

		std::pair<int64_t,int64_t> d=mod_fact(n/m,m);
		int64_t second=d.second+n/m;
		int64_t first;
		if((n/m)%2==0){
			first=1;
		}else{
			first=m-1;
		}
		for(int64_t i1=1;i1<=(n%m);i1++){
			first=normalize_mod(first*i1,m);
		}
		return std::make_pair(first,second);
	}
}

int main(){
	int64_t n,a,b,k;
	cin>>n>>a>>b>>k;
	int64_t ans=0;
	int64_t table[n+1];
	int64_t m=998244353;
	table[0]=1;
	for(int64_t i1=1;i1<=n;i1++){
		table[i1]=normalize_mod(((table[i1-1]*(n-i1+1))%m)*mod_inv(i1,m),m);
	}
	for(int64_t i1=0;i1<=n;i1++){
		if((k-a*i1)%b!=0){
			continue;
		}
		int64_t i2=(k-a*i1)/b;
		if(i2<0){
			break;
		}
		if(i2>n){
			continue;
		}
		ans=normalize_mod(ans+table[i1]*table[i2],m);
	}
	cout<<ans<<endl;


}