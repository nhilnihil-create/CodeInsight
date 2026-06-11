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
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
	string s,t="",u="",v="";cin>>s;
	int n=s.size();
	rep(i,n-1){
		if(s[i]=='A')t.PB('Y');
		else if(s[i]=='B'&&s[i+1]=='C'){
			t.PB('X');
			i++;
		}
        else t.PB(s[i]);
	}
	n=t.size();
	ll sumy[n+1];
	sumy[0]=0;
	if(t[0]=='Y')sumy[0]=1;
	for(int i=1;i<n;++i){
		if(t[i]=='Y'){
			sumy[i]=sumy[i-1]+1;
		}
		else if(t[i]=='X'){
			sumy[i]=sumy[i-1];
		}
		else{
			sumy[i]=0;
		}
	}
	ll ans=0;
	rep(i,n){
		if(t[i]=='X')ans+=sumy[i];
	}
	cout<<ans<<endl;
}
