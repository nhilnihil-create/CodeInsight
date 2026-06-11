#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm(a, b) (a)/__gcd((a),(b))*(b)
#define CEIL(a, b) (a) / (b) + (((a) % (b))?1:0)
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

    int m, k;
    cin >> m >> k;
    if(k >= (1 << m)) {
        cout << -1 << endl;
        return 0;

    }
    if(m == 0) {
        cout << "0 0" << endl;
        return 0;

    }
    if(m == 1) {
        if(k == 0) {
            cout << "1 1 0 0" << endl;

        } else {
            cout << -1 << endl;

        }
        return 0;
    }

    for(int i = 0; i < (1 << m); ++i) {
        if(i != k) {
            cout << i << " ";

        }
    }
    cout << k << " ";
    for(int i = (1 << m) - 1; i >= 0; --i) {
        if(i != k) {
            cout << i << " ";

        }
    }
    cout << k << endl;
    return 0;
}

