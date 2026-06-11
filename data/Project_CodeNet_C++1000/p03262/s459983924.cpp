#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    ll N, X;
    cin >> N >> X;
    vec x(N);
    REP(i,0,N) cin >> x[i];

    ASC(x);
    ll s = lower_bound(ALL(x), X) - x.begin() - 1;
    ll d;
    if(s >= 0) d = abs(X - x[s]);
    else d = abs(X - x[0]);
    for(ll i=s; i>=1; --i) d = gcd(d, abs(x[i]-x[i-1]));
    if(s+1<N) {
        d = gcd(d, abs(x[s+1]-x[0]));
        REP(i,s+1,N-1) d = gcd(d, abs(x[i+1]-x[i]));
    }
    PR(d);

    return 0;
}

/*



*/