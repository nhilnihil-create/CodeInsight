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

void Init(int N);
int Root(int x);
bool Unite(int x, int y);

int root[SIZE];
int sz[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL N, M;
    cin >> N >> M;
    Init(N);

    vector<P> bridges(M);
    for(int i = 0; i < M; ++i) {
        cin >> bridges[i].F >> bridges[i].S;
    }

    vector<LL> res;
    res.pb(N * (N - 1) / 2);
    LL t = res[0];
    for(int i = M - 1; i >= 0; --i) {
        Root(bridges[i].F);
        Root(bridges[i].S);
        LL szf, szs;
        szf = sz[bridges[i].F];
        szs = sz[bridges[i].S];
        if(Unite(bridges[i].F, bridges[i].S)) {
            t -= szf * szs;
        }
        res.pb(t);
    }
    reverse(all(res));

    for(int i = 1; i < res.size(); ++i) {
        cout << res[i] << endl;
    }

    return 0;
}

void Init(int N) {
    for(int i = 1; i <= N; ++i) {
        root[i] = i;
        sz[i] = 1;
    }
}

int Root(int x) {
    if(x == root[x]) return x;
    root[x] = Root(root[x]);
    sz[x] = sz[root[x]];
    return root[x];
}

bool Unite(int x, int y) {
    x = Root(x);
    y = Root(y);
    if(x == y) return false;

    sz[x] += sz[y];
    sz[y] = sz[x];
    root[x] = y;

    return true;
}
