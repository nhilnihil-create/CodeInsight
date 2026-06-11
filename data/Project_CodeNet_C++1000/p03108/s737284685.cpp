#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define log_2(a) (log((a)) / log(2))
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

int root[SIZE];
LL sz[SIZE];

void init() {
    for(int i = 0; i < SIZE; ++i) {
        root[i] = i;
        sz[i] = 1;
    }
}

int Root(int x) {
    if(x == root[x]) return x;

    int rt = Root(root[x]);
    sz[x] = sz[rt];
    return rt;
}

bool Unite(int x, int y) {
    int rx, ry;
    rx = Root(x);
    ry = Root(y);

    if(rx == ry) return false;
    if(sz[rx] > sz[ry]) {
        root[ry] = rx;
    } else {
        root[rx] = ry;
    }

    sz[rx] += sz[ry];
    sz[ry] = sz[rx];
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL N, M;
    cin >> N >> M;
    init();

    vector<P> v(M);
    for(int i = 0; i < M; ++i) {
        cin >> v[i].F >> v[i].S;
    }

    LL res = N * (N - 1) / 2;
    vector<LL> r;
    for(int i = M - 1; i >= 0; --i) {
        r.pb(res);
        Root(v[i].F);
        Root(v[i].S);
        LL a = sz[v[i].F];
        LL b = sz[v[i].S];
        if(Unite(v[i].F, v[i].S)) {
            res -= a * b;
        }
    }
    reverse(all(r));

    for(int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }

    return 0;
}

