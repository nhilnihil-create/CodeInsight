#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm(a, b) (a)/__gcd((a),(b))*(b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
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

    int n, K;
    cin >> n >> K;
    vector<LP> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].F >> v[i].S;

    }

    LL res = LINF;
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v.size(); ++j) {
            for(int k = 0; k < v.size(); ++k) {
                for(int l = 0; l < v.size(); ++l) {
                    LL ymax, ymin, xmax, xmin;
                    ymax = max({v[i].S, v[j].S, v[k].S, v[l].S});
                    ymin = min({v[i].S, v[j].S, v[k].S, v[l].S});
                    xmax = max({v[i].F, v[j].F, v[k].F, v[l].F});
                    xmin = min({v[i].F, v[j].F, v[k].F, v[l].F});
                    int c = 0;
                    for(int m = 0; m < n; ++m) {
                        if(xmin <= v[m].F && v[m].F <= xmax &&
                            ymin <= v[m].S && v[m].S <= ymax) {
                            ++c;
                        }
                    }
                    if(c >= K) {
                        res = min(res, (ymax - ymin) * (xmax - xmin));
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
