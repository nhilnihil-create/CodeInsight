#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"

#define mod 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 92233720368547758070
#define nyan "(=^･ω･^=)"
#define mkp make_pair
typedef long long ll;
using namespace std;

ll N,A,B,K,C[300001],ans;

ll pw(ll x, ll y){
	ll a=1;
	while(y){
		if(y%2)
			a=a*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return a;
}

ll modinv(ll x){
	return pw(x,mod-2);
}

int main(){
	cin>>N>>A>>B>>K;
	C[0]=1;
	for(int i=1;i!=N+1;++i){
		C[i]=C[i-1]*(N+1-i)%mod*modinv(i)%mod;
	}
	for(int i=0;i!=N+1;++i){
		if(A*i>K)break;
		if((K-A*i)%B==0){
			if((K-A*i)/B<=N){
				ans=(ans+C[i]*C[(K-A*i)/B])%mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}