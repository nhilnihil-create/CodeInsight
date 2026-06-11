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
    ll N, Y;
    cin >> N >> Y;
    Y /= 1000;

    bool f = false;
    REP(a,0,Y/10+1) {
        REP(b,0,Y/5+1) {
            ll c = N - a - b;
            if(c >= 0 && 10*a+5*b+c == Y) {
                PS(a); PS(b); PR(c);
                f = true;
                break;
            }
        }
        if(f) break;
    }
    if(!f) PR("-1 -1 -1");

    return 0;
}

/*

10a + 5b + c = Y
c = N - a - b

*/