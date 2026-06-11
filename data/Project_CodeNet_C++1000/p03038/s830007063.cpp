#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

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
#define ASC(x) sort(ALL((x)))
#define DESC(x) sort(ALL((x)),greater<pair<ll,ll>>())
#define pb push_back

int main()
{
    ll N, M;
    cin >> N >> M;
    vec A(N);
    REP(i,0,N) cin >> A[i];
    vector<pair<ll,ll>> P;
    REP(i,0,M) {
        ll b, c;
        cin >> b >> c;
        P.pb({c, b});
    }

    ASC(A);
    DESC(P);
    ll k = 0, l;
    FORR(p,P) {
        ll b = p.second, c = p.first;
        l = 0;
        REP(i,k,MIN(b+k,N)) {
            if(A[i] < c) {
                A[i] = c;
                ++l;
            }
            else break;
        }
        k += l;
        if(k >= N) break;
    }

    ll sum = 0;
    REP(i,0,N) sum += A[i];
    PR(sum);


    return 0;
}

/*



*/