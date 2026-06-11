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

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];

    }

    vector<LL> sum;
    for(int i = 0; i < n - 1; ++i) {
        LL s = v[i];
        sum.pb(s);
        for(int j = i + 1; j < n; ++j) {
            s += v[j];
            sum.pb(s);

        }
    }
    sum.pb(v[n - 1]);
    sort(all(sum), greater<LL>());

    LL res = 0;
    for(int i = 45; i >= 0; --i) {
        int c = 0;
        LL t = res + (1ll << i);
        for(int j = 0; j < sum.size(); ++j) {
            if((t & sum[j]) == t) {
                ++c;

            }
        }
        if(c >= k) {
            res += (1ll << i);

        }
    }
    cout << res << endl;
    return 0;
}

