#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
 os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif


#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define I insert 
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector< pii >


const int mod=998244353;
inline int mul(int a,int b){return (a*1ll*b)%mod;}
inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
inline int inv(int a){return power(a,mod-2);}
inline void modadd(int &a,int &b){a+=b;if(a>=mod)a-=mod;} 


const int M = 3e5+15;
int fact[M], ifact[M];

void pre(){
	int i,j;
	fact[0]=1;
	for(i=1;i<M;i++){
		fact[i]= mul(fact[i-1], i);
	}
	ifact[M-1]= inv(fact[M-1]);
	for(i=M-2;i>=0;i--){
		ifact[i] = mul(i+1, ifact[i+1]);
	}
}

inline int ncr(int x, int y){
	return mul(fact[x], mul(ifact[y], ifact[x-y]));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	ll N, A, B, K;
	pre();
	cin>>N>>A>>B>>K;
	int ans =0 ;
	for(ll i=0;i<=N;i++){
		ll rem = K - i*A;
		if(rem<0 || (rem%B)!=0) continue;
		ll cb = rem/B; if(cb>N) continue;
		// if(cb+i < N) continue;
		// trace(i, cb);
		int cur = mul(ncr(N, i), ncr(N, cb));
		ans = add(ans, cur);
	}
	cout<<ans<<"\n";

}
