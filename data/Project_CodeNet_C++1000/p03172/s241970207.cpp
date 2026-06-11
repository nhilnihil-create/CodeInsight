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

int dp[105][100005];
int in[100005];
int a[105];

// dp[i][j] = no. of ways to distribute j candies to first i children

void solve(int TEST_CASE){
    int n, k;
    cin >> n >> k;
    fr(i,n) cin >> a[i];
    fill(dp);
    int cc;
    fr(i,a[0]+1) dp[1][i] = 1;
    frA(i,2,n){
        fill(in);
        fr(j,k+1){
            in[j]=(in[j]+dp[i-1][j])%MOD;
            if(j+a[i-1]<100003) in[j+a[i-1]+1]=(in[j+a[i-1]+1]-dp[i-1][j])%MOD;
        }
        dbg{
            cout << "in "<<i<<": ";
            fr(j,k+2) cout << in[j] << ",";
            cout << endl;
        }
        cc=0;
        fr(j,k+3) {
            cc = (cc+in[j])%MOD;
            dp[i][j] = cc;
        }
    }
    dbg{
        fr(i,n+1){
            fr(j,k+1){
                cout << dp[i][j] <<",";
            }
            cout << endl;
        }
    }
    cout << (dp[n][k]+MOD)%MOD;
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