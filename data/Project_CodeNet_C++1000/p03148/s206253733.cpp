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

ll N, K;

int main() {
    cin >> N >> K;
    vector<Pll> A(N);
    ll t, d;
    REP(i, N) {
        cin >> t >> d;
        A[i] = make_pair(t, d);
    }
    sort(ALL(A), [](const auto& lh, const auto& rh) {
        return lh.second > rh.second;
    });
    set<ll> T;
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    ll score = 0;
    REP(i, K) {
        score += A[i].second;
        if(T.find(A[i].first)!=T.end()) {
            Q.push(A[i].second);
        }
        T.insert(A[i].first);
    }
    ll ans = score + SQ(T.size());
    FOR(i, K, N-1) {
        if(T.find(A[i].first)==T.end() && Q.size() > 0) {
            score -= Q.top();
            score += A[i].second;
            T.insert(A[i].first);
            ans = max(ans, ll(score + SQ(T.size())));
            Q.pop();
        }
    }
    cout << ans << endl;
	return 0;
}