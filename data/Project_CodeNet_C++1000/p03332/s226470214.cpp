#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=998244353;
const int size=3e5+1;
const int inf=1e9;
template<typename T> pair<T,T> bezout(T a,T b){// ax + by = 1, gcd(a, b)=1
	if(__gcd(a, b) != 1) return {0, 0};
	else if(b == 1) return {1, - a + 1};
    else if(a % b == 1) return {1, - a / b};
	else{
		pair<T,T> p = bezout(b, a % b);
		swap(p.first, p.second);
		p.second = p.second - (a / b) * p.first;
        return p;
	}
}
long fact[300010] = {};
void calc(long n){
	fact[0] = 1;
	rep(i,1,n+1) fact[i] = (fact[i-1] * i) % mod;
	return;
}
long modcomb(long n, long r){//nCr mod p
	if(n < r) return 0;
	long x = (fact[n-r] * fact[r]) % mod;
	long res = 1; int i = 0;
	while( (mod-2) >= (1<<i) ){
		if( (mod-2) & (1<<i) ) (res *= x) %= mod;
		i++; x = (x * x) % mod;
	}
    return (res * fact[n]) % mod;
}
int main(){
	int N; long A,B,K; cin>>N>>A>>B>>K;
	long g = __gcd(__gcd(A, B), K);
	A /= g; B /= g; K /= g;
	pair<long,long> p = bezout(A, B);
	p.first *= K; p.second *= K;
	if(p.first > 0){
		p.second += p.first / B * A;
		p.first %= B;
	}else if(p.first < 0){
		p.second -= (- p.first + B - 1) / B * A;
		p.first = (p.first % B + B) % B;
	}
	long ans = 0; calc(N);
	while(p.second > N){ p.first += B; p.second -= A; }
	while(p.first <= N && 0 <= p.second){
		ans += (modcomb(N, p.first) * modcomb(N, p.second)) % mod;
		ans %= mod;
		p.first += B;
		p.second -= A;
	}cout<<ans<<endl;
}