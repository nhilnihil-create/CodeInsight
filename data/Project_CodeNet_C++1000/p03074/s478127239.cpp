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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi a;
    vector<bool>b;
    char m=s[0];
    int cnt=0;
    rep(i,s.size()){
        if(s[i]==m){
            cnt++;
        }
        else{
            if(m=='1')b.PB(true);
            else b.PB(false);
            a.PB(cnt);
            cnt=1;
            m=s[i];
        }
    }
    a.PB(cnt);
    if(m=='1')b.PB(true);
    else b.PB(false);
    int l=0,c=0,d=0;
    vi ans;
    rep(i,a.size()){
        l+=a[i];
        if(!b[i])c++;
        if(c==k+1){
            ans.PB(l-a[i]);
            while(c>k){
                l-=a[d];
                if(!b[d])c--;
                d++;
            }
        }
    }
    ans.PB(l);
    sort(all(ans));
    reverse(all(ans));
    cout<<ans[0]<<endl;
}