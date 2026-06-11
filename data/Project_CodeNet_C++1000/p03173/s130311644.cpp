// JavaProgram.cpp
// Author : Priydarshi Singh (@dryairship)
// One cat just leads to another. One bug leads to two others.

#include <bits/stdc++.h>
using namespace std;

// I like my types defined.
typedef long long           ll;
typedef pair<int, int>      pii;
typedef pair<ll, ll>        pll;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef vector<pii>         vii;
typedef vector<pll>         vll;
typedef set<int>            si;
typedef map<string, int>    msi;
typedef map<int, int>       mii;

// Traditional science is all about finding "hashtag define"s.
#define fr(i, n)            for(int i=0; i<(n); ++i)
#define frC(i, n, c)        for(int i=0; (i<(n)) && (c); ++i)
#define frA(i, a, n)        for(int i=a; i<=(n); ++i)
#define frD(i, a, n)        for(int i=a; i>=(n); --i)
#define fill(a)             memset(a, 0, sizeof(a))
#define fill1(a)            memset(a, -1, sizeof(a))
#define revsort(a, b)       sort(a, b, greater<int>())
#define ff                  first
#define ss                  second
#define pb                  push_back 
#define dout                if(DEBUGGING) cout
#define dbg                 if(DEBUGGING) 
#define endl                "\n"

// When you realize MOD > INF...
int DEBUGGING    =          0;
const int INF    =          1000000000;
const int MOD    =          1000000007;
const ll LINF    =          1e18;
const double PI  =          3.1415926535897932;
const double EPS =          1e-7;

// I'D SPAM. Hehe.
ll gcdEx                    (ll a, ll b, ll *x, ll *y){if(!a){*x=0;*y=1;return b;} 
ll x1,y1,gcd=gcdEx          (b%a,a,&x1,&y1); *x=y1-(b/a)*x1;*y=x1; return gcd;}
ll modI(ll b, ll m)         {ll x,y;gcdEx(b,m,&x,&y);return (x%m+m)%m;}
ll modD(ll a, ll b)         {return (modI(b,MOD)*(a%MOD))%MOD;}
ll modS(ll a, ll b)         {return ((a%MOD)-(b%MOD)+MOD)%MOD;}
ll modP(ll x, ll y)         {ll r=1; x%=MOD; while(y>0){if(y&1){r=(r*x)%MOD;} y=y>>1; x=(x*x)%MOD;} return r;}
ll modA(ll a, ll b)         {return ((a%MOD)+(b%MOD))%MOD;}
ll modM(ll a, ll b)         {return ((a%MOD)*(b%MOD))%MOD;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a[500];
ll dp[500][500];
ll c[500][500];

// dp[i][j] = min cost of combining i length segment starting at index j

void solve(int TEST_CASE){
    int n;
    cin >> n;
    fr(i, n) cin >> a[i];
    fr(i,n) dp[1][i] = a[i], c[1][i]=0;
    ll cs, ms, ts, ds;
    frA(i,2,n){
        fr(j,n-i+1){
            ms = LINF;
            cs = 0;
            frA(k,1,i-1){
                ts = c[k][j]+c[i-k][j+k];
                dout << i << ", " << j << ", " << k << " - " << ts <<endl;
                if(ts<ms){
                    ms = ts;
                    ds = dp[k][j]+dp[i-k][j+k];
                }
            }
            dout << i << ", " << j << " : ms=" << ms << ", cs="<<cs <<endl;
            dp[i][j] = ds;
            c[i][j] = ms+ds;
        }
    }
    dbg{
        fr(i,n+1){
            fr(j,n){
                cout << dp[i][j] << ",";
            }
            cout << endl;
        }
            cout << endl;
        fr(i,n+1){
            fr(j,n){
                cout << c[i][j] << ",";
            }
            cout << endl;
        }
    }
    cout << c[n][0];
}

int main(int argc, char* argv[]){
    if(argc==2 && argv[1][1]=='v') DEBUGGING = 1;
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin.exceptions(cin.failbit);
    int nTestCases=1;
    //cin >> nTestCases;
    frA(i,1,nTestCases) solve(i);
    return 0;
}