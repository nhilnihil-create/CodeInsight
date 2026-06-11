#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;
using LL = long long;
using ldouble = long double;
using P = pair<int, int>;
using LP = pair<LL, LL>;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<LL> Div(LL n) {
    vector<LL> ret;
    for(LL i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);
            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<pair<LP, LL>> v(N);
    for(int i = 0; i < N; ++i) {
        cin >> v[i].F.F >> v[i].F.S >> v[i].S;

    }

    LL res = 0;
    for(int i = 0; i < 8; ++i) {
        vector<LP> sum;
        for(int j = 0; j < N; ++j) {
            LL s = 0;
            if(i & 1) s += v[j].F.F;
            else s -= v[j].F.F;
            if((i >> 1) & 1) s += v[j].F.S;
            else s -= v[j].F.S;
            if((i >> 2) & 1) s += v[j].S;
            else s -= v[j].S;
            sum.pb(MP(s, j));

        }
        sort(all(sum), greater<LP>());

        LL a = 0, b = 0, c = 0;
        for(int j = 0; j < M; ++j) {
            int pos = sum[j].S;
            a += v[pos].F.F;
            b += v[pos].F.S;
            c += v[pos].S;

        }
        res = max(res, llabs(a) + llabs(b) + llabs(c));
    }
    cout << res << endl;
    return 0;
}

