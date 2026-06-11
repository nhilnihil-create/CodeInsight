#include "bits/stdc++.h"

using namespace std;

using ll = long long;

template<typename T> using V = std::vector<T>;
using Vi = V<int>;
using VVi = V<V<int>>;
using Vl = V<ll>;
using VVl = V<V<ll>>;
using Vs = V<string>;

template<typename T1, typename T2> using P = std::pair<T1, T2>;
using Pii = P<int, int>;
using Pll = P<ll, ll>;
using Pdd = P<double, double>;

template<typename T1, typename T2> using M = std::map<T1, T2>;
using Mii = M<int, int>;
using Mll = M<ll, ll>;
using Msi = M<string, int>;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP2(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define RREP(i,s,e) for(int i=(int)(s);i>=(int)(e);--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin(),ie=(c).end();i!=ie;++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin(),ie=(c).rend();i!=ie;++i)
#define ALL(c) (c).begin(), (c).end()

const double PI = acos(-1);
const ll MOD = 1e9+7;

int n, m;

int main() {
    cin >> n >> m;

    cout << "100 100" << '\n';
    int bcnt = m-1, wcnt = n-1;
    REP(i, 50) {
        if (i%2 == 0 || wcnt == 0) {
            string s(100, '#');
            cout << s << '\n';
            continue;
        }
        REP(j, 100) {
            if (j == 0 || j == 99) {
                cout << '#';
                continue;
            }
            if ((i+j)%2 == 0 && wcnt > 0) {
                cout << '.';
                wcnt--;
            } else {
                cout << '#';
            }
        }
        cout << '\n';
    }
    REP(i, 50) {
        if (i%2 == 0 || bcnt == 0) {
            string s(100, '.');
            cout << s << '\n';
            continue;
        }
        REP(j, 100) {
            if (j == 0 || j == 99) {
                cout << '.';
                continue;
            }
            if ((i+j)%2 == 0 && bcnt > 0) {
                cout << '#';
                bcnt--;
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }

    return 0;
}
