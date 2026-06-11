#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(a) ll((a).size())
#define all(a) (a).begin(), (a).end()
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
const ll MOD = 1E9+7;
const ll INF = 1E18;
const double EPS = 1E-9;
const double PI = atan(1.0) * 4.0;
template<class T> T getbit(T s, int i) {return s >> i & 1;}
template<class T> void flipbit(T& s, int i) {s ^= (1LL << i);}
constexpr int cntbit(ll x) {return __builtin_popcountll(x);}
constexpr int lg2(ll x) {return __lg(x);} // return int(log2(x))
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a%MOD;a=a*a%MOD;p>>=1LL;} return res;}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,a,b;
	cin>>n>>a>>b;
	if(a+b-1>n||a*b<n) exit(puts("-1\n")*0);
	int cur=n;
	Ford(i,b,1){
		if(cur-a>=i-1){
			For(j,cur-a+1,cur) cout<<j<<' ';
			cur-=a;
		}
		else{
			For(j,i,cur) cout<<j<<' ';
			cur=i-1;
		}
	}
	cout<<'\n';
}

