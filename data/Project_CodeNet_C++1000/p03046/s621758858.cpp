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
    int m,k;cin>>m>>k;
    ll n=1;
    int cnt=0;
    while(cnt<m){
        n*=2;
        cnt++;
    }
    if(n-1<k){
        cout<<-1<<endl;
    }
    else{
        if(m==0){
            if(k!=0)cout<<-1<<endl;
            else cout<<0<<" "<<0<<endl;
        }
        else if(m==1){
            if(k!=0){
                cout<<-1<<endl;  
            }
            else cout<<0<<" "<<0<<" "<<1<<" "<<1<<endl;
        }
        else{
            vi a(n*2,0);
            if(k==0){
                int l=0;
                for(int i=0;i<n*2;i+=2){
                    a[i]=l;
                    a[i+1]=l;
                    l++;
                }
            }
            else{
            a[1]=k;
            a[n*2-1-(n-2)]=k;
            int l=1;
            for(int i=1;i+n*2-1-(n-2)<n*2;++i){
                if(l==k)l++;
                a[n*2-1-(n-2)+i]=l;
                a[n*2-1-(n-2)-i]=l;
                l++;
            }}
            rep(i,n*2){
                if(i!=n*2-1)cout<<a[i]<<" ";
                else cout<<a[i]<<endl;
            }
        }
    }
}