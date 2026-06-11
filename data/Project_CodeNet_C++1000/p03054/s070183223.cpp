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

    int H, W, N;
    cin >> H >> W >> N;
    P s;
    cin >> s.F >> s.S;

    string S, T;
    cin >> S >> T;

    int nh, nw;
    nh = s.F;
    nw = s.S;
    // takahashi : L
    // aoki      : R
    for(int i = 0; i < N; ++i) {
        if(S[i] == 'L') --nw;
        if(nw == 0) {
            cout << "NO" << endl;
            return 0;
        }
        if(T[i] == 'R' && nw < W) ++nw;
    }

    nh = s.F;
    nw = s.S;
    // takahashi : R
    // aoki      : L
    for(int i = 0; i < N; ++i) {
        if(S[i] == 'R') ++nw;
        if(nw == W + 1) {
            cout << "NO" << endl;
            return 0;
        }
        if(T[i] == 'L' && nw > 1) --nw;
    }

    nh = s.F;
    nw = s.S;
    // takahashi : U
    // aoki      : D
    for(int i = 0; i < N; ++i) {
        if(S[i] == 'U') --nh;
        if(nh == 0) {
            cout << "NO" << endl;
            return 0;
        }
        if(T[i] == 'D' && nh < H) ++nh;
    }

    nh = s.F;
    nw = s.S;
    // takahashi : D
    // aoki      : U
    for(int i = 0; i < N; ++i) {
        if(S[i] == 'D') ++nh;
        if(nh == H + 1) {
            cout << "NO" << endl;
            return 0;
        }
        if(T[i] == 'U' && nh > 1) --nh;
    }
    
    cout << "YES" << endl;
    return 0;
}
