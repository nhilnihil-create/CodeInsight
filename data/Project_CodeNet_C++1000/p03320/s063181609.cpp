#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
#define vv(a,b,c,d) vector<vector<a> >(b,vector<a>(c,d))
#define vvv(a,b,c,d,e) vector<vector<vector<a> > >(b,vv(a,c,d,e))
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;



ll s(ll x) {
    ll re = 0;
    while (x > 0) {
        re += x % 10;
        x /= 10;
    }
    RT re;
}

bool cmp(ll x, ll y) {
    RT x*s(y) <= y * s(x);
}

void solve(int K) {
    for (int n = 1; n <= 1000001 &&K > 0; ++n) {
        bool ok = true;
        for (int m = n + 1; m <= 10000001; ++m) {
            if (!cmp(n, m)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            K--;
            cout << n << ',' << endl;
        }
    }

}

const int MAGIC[36] = {
1,
2,
3,
4,
5,
6,
7,
8,
9,
19,
29,
39,
49,
59,
69,
79,
89,
99,
199,
299,
399,
499,
599,
699,
799,
899,
999,
1099,
1199,
1299,
1399,
1499,
1599,
1699,
1799,
1899
};

void solve2(int K) {
    ll d = 1, cur = 0;
    rep(i, K) {
        ll x = cur + d, y = cur + d * 10;
        if (cmp(x, y)) {
            cur = x;
        } else {
            cur = y;
            d *= 10;
        }
        cout << cur << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    int K;
    cin >> K;

    solve2(K);
}