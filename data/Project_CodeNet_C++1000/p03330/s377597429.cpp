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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    int d[35][35];
    for(int i = 1; i <= c; ++i) {
        for(int j = 1; j <= c; ++j) {
            cin >> d[i][j];

        }
    }

    vector<int> v[3];
    map<P, int> mp;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            int a;
            cin >> a;
            v[(i + j) % 3].pb(a);
            mp[MP((i + j) % 3, a)]++;

        }
    }
    for(int i = 0; i < 3; ++i) {
        sort(all(v[i]));
        v[i].erase(unique(all(v[i])), v[i].end());

    }

    int res = INF;
    for(int i = 1; i <= c; ++i) {
        int sum_i = 0;
        for(int l = 0; l < v[0].size(); ++l) {
            sum_i += d[v[0][l]][i] * mp[MP(0, v[0][l])];

        }

        for(int j = 1; j <= c; ++j) {
            if(i == j) {
                continue;

            }
            int sum_j = 0;
            for(int l = 0; l < v[1].size(); ++l) {
                sum_j += d[v[1][l]][j] * mp[MP(1, v[1][l])];

            }

            for(int k = 1; k <= c; ++k) {
                if(j == k || i == k) {
                    continue;

                }
                int sum_k = 0;
                for(int l = 0; l < v[2].size(); ++l) {
                    sum_k += d[v[2][l]][k] * mp[MP(2, v[2][l])];

                }
                res = min(res, sum_i + sum_j + sum_k);
                /*
                cout << i << " " << j << " " << k << endl;
                cout << sum_i << " " << sum_j << " " << sum_k << endl << endl;
                cout << res << endl;
                */

            }
        }
    }
    cout << res << endl;
    return 0;
}
