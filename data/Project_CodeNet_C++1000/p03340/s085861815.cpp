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

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];

    }

    int l, r;
    l = r = 0;
    LL res = 0;
    int bic = 0;
    int bi[21] = {};
    while(l < n) {
        bool f = true;
        while(r < n && f) {
            int t = v[r];
            int b = 0;
            while(t > 0) {
                if(t & 1) {
                    ++bi[b];
                    if(bi[b] == 2) {
                        ++bic;
                        f = false;
                    }
                }
                t >>= 1;
                ++b;
            }
            if(f) {
                res += r - l + 1;
                ++r;
            }
        }

//        cout << l << " " << r << " " << res << endl;
        if(f) {
            ++l;
            continue;
        }

        while(l < r && !f) {
            int t = v[l];
            int b = 0;
            while(t > 0) {
                if(t & 1) {
                    --bi[b];
                    if(bi[b] == 1) {
                        --bic;

                    }
                }
                t >>= 1;
                ++b;
            }
            ++l;
            if(bic == 0) {
                f = true;
                res += r - l + 1;

            }
        }
        ++r;
//        cout << l << " " << r << " " << res << endl;
    }
    cout << res << endl;
    return 0;
}

