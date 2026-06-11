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

int main()
{
    ll N, M;
    cin >> N >> M;
    vec X(M);
    REP(i,0,M) cin >> X[i];

    if(N >= M) PR(0);
    else {
        vector<pll> D(M-1);
        ASC(X);
        REP(i,0,M-1) {
            D[i].first = X[i+1] - X[i];
            D[i].second = -i;
        }
        DESC(D);
        vec P(N-1);
        REP(i,0,N-1) P[i] = -D[i].second;
        ASC(P);
        ll k = X[0], sum = 0;
        REP(i,0,N-1) {
            sum += X[P[i]] - k;
            k = X[P[i]+1];
        }
        sum += X[M-1] - k;
        PR(sum);
    }
    return 0;
}

/*



*/