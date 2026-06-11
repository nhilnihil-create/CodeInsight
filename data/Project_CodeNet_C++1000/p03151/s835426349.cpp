#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pdd> vdd;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mem(a,b) memset(a, b, sizeof(a) )
#define all(x) (x).begin(),(x).end()
#define INF 1000000000000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
	int n;cin>>n;
	vl a(n),b(n),c(n);
	rep(i,n){
		cin>>a[i];
	}
	rep(i,n){
		cin>>b[i];
	}
	rep(i,n){
		c[i]=a[i]-b[i];
	}
	sort(all(c));
	ll sum1=0,cnt1=0,sum2=0,cnt2=0;
	rep(i,n){
		if(c[i]<0){
			sum1+=c[i];
			cnt1++;
		}
	}
	rep(i,n){
		if(abs(sum1)<=sum2){
			cout<<cnt1+cnt2<<endl;
			return 0;
		}
		if(c[n-1-i]>0){
			sum2+=c[n-1-i];
			cnt2++;
		}	
	}
    if(abs(sum1)<=sum2){
		cout<<cnt1+cnt2<<endl;
	    return 0;
	}
	cout<<-1<<endl;
}
