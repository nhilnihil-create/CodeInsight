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

int main(){
    string s;cin>>s;
    int n=s.size();
    ll dpa[n+1],dpab[n+1],dpabc[n+1];
    vl a(n+1);
    a[0]=1;
    for(int i=0;i<n;++i){
        a[i+1]=3*a[i];
        a[i+1]%=MOD;
    }
    mem(dpa,0);mem(dpab,0);mem(dpabc,0);
    int cnt=0;
    if(s[0]=='A'||s[0]=='?'){
        dpa[0]=1;
    }
    if(s[0]=='?')cnt++;
    for(int i=0;i<n-1;++i){
        if(s[i+1]=='?'){
            dpa[i+1]=dpa[i]*3+a[cnt];
            dpa[i+1]%=MOD;
            dpab[i+1]=dpab[i]*3+dpa[i];
            dpab[i+1]%=MOD;
            dpabc[i+1]=dpabc[i]*3+dpab[i];
            dpabc[i+1]%=MOD;
            cnt++;
        }
        else if(s[i+1]=='A'){
            dpa[i+1]=dpa[i]+a[cnt];
            dpa[i+1]%=MOD;
            dpab[i+1]=dpab[i];
            dpabc[i+1]=dpabc[i];
        }
        else if(s[i+1]=='B'){
            dpa[i+1]=dpa[i];
            dpab[i+1]=dpab[i]+dpa[i];
            dpab[i+1]%=MOD;
            dpabc[i+1]=dpabc[i];
        }
        else if(s[i+1]=='C'){
            dpa[i+1]=dpa[i];
            dpab[i+1]=dpab[i];
            dpabc[i+1]=dpabc[i]+dpab[i];
            dpabc[i+1]%=MOD;
        }
    }
    cout<<dpabc[n-1]<<endl;
}