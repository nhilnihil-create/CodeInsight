#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm(a, b) (a)/__gcd((a),(b))*(b)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<int> Div(int n) {
    vector<int> ret;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);

            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

LL solve(int bi);

vector<pair<LP, LL>> v;
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    LL a, b, c;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        v.pb(MP(MP(a, b), c));

    }

    LL res = 0;
    for(int i = 0; i < 8; ++i) {
        res = max(res, solve(i));

    }
    cout << res << endl;
    return 0;
}

LL solve(int bi) {
    vector<LL> t;
    for(int i = 0; i < n; ++i) {
        LL sum = 0;
        for(int j = 0; j < 3; ++j) {
            if((bi >> j) & 1) {
                if(j == 0) {
                    sum += v[i].F.F;

                }
                if(j == 1) {
                    sum += v[i].F.S;

                }
                if(j == 2) {
                    sum += v[i].S;

                }
            } else {
                if(j == 0) {
                    sum -= v[i].F.F;

                }
                if(j == 1) {
                    sum -= v[i].F.S;

                }
                if(j == 2) {
                    sum -= v[i].S;

                }
            }
        }
        t.pb(sum);

    }
    sort(all(t), greater<LL>());

    LL res = 0;
    for(int i = 0; i < m; ++i) {
        res += t[i];

    }

    return res;
}
