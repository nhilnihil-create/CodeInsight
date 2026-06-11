#include <bits/stdc++.h>
#define SIZE 300005
#define MOD 1000000007LL
#define EPS 1e-10
#define INF 2147483647
#define LLINF 9223372036854775807
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DOWN(i,b,a) for(int i=b;i>=a;i--)
#define SET(a,c) memset(a,c,sizeof a)
#define BIT(i,j) ((i)>>(j))&1
#define ALL(o) (o).begin(), (o).end()
#define ERASE(o) (o).erase(unique((o).begin(),(o).end()), (o).end())
#define SQ(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pll;
typedef pair<int, int> Pii;
typedef pair<double, double> Pdd;
typedef complex<double> dcomplex;
template<typename T> inline void priv(vector<T>a){REP(i,a.size()){cerr<<a[i]<<((i==a.size()-1)?"\n":" ");}}
ll gcd(ll a,ll b){int c=max(a,b);int d=min(a,b);return c==0||d==0?c:gcd(c%d,d);}
ll lcm(ll a,ll b){return a==0||b==0?0:a*b/gcd(a,b);}
ll modfact(ll a){ll b=1;FOR(i,2,a)b=b*i%MOD;return b;}
ll modpow(ll a, ll n){ll b=1;while (n>0){if(n&1)b=b*a%MOD;a=a*a%MOD;n>>=1;}return b;}
ll modcomb(ll n, ll k){ll b=1;k=min(n-k,k);DOWN(i,n,n-k+1)b=b*i%MOD;return b*modpow(modfact(k),MOD-2)%MOD;}

int length[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    REP(i, M) cin >> A[i];
    sort(ALL(A)); reverse(ALL(A)); 
    // priv(A);
    vector<int> dp(N + 1, -INF);
    dp[0] = 0;
    FOR(i, 1, N) {
        REP(j, M) {
            if(i < length[A[j]]) continue;
            if(dp[i-length[A[j]]] == -INF) continue;
            dp[i] = max(dp[i], dp[i-length[A[j]]] + 1);
        }
    }
    // priv(dp);
    while(N > 0) {
        REP(j, M) {
            if(N < length[A[j]]) continue;
            if(dp[N-length[A[j]]] + 1 == dp[N]) {
                cout << A[j];
                N -= length[A[j]];
                // cerr << N << " " << A[j] << endl;
                break;        
            }
        }
    }
    cout << endl;
	return 0;
}
