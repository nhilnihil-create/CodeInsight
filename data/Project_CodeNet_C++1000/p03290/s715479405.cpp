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
    ll D, G;
    cin >> D >> G;
    vec P(D), C(D);
    REP(i,0,D) cin >> P[i] >> C[i];

    ll m = INF;
    REP(i,0,1<<D) {
        ll cnt = 0, sum = 0;
        REP(j,0,D) {
            if((i>>j) & 1) {
                sum += 100 * (j+1) * P[j] + C[j];
                cnt += P[j];
            }
        }
        if(sum >= G) {
            m = MIN(m,cnt);
            continue;
        }
        for(ll j=D-1; j>=0; --j) {
            if(((i>>j) & 1) == 0) {
                if(sum + 100 * (j+1) * P[j] < G) {
                    sum += 100 * (j+1) * P[j];
                    cnt += P[j];
                }
                else {
                    ll n = (G-sum+100*(j+1)-1) / (100*(j+1));
                    sum += 100 * (j+1) * n;
                    cnt += n;
                    break;
                }
            }
        }
        if(sum >= G) m = MIN(m,cnt);
    }
    PR(m);

    return 0;
}

/*



*/