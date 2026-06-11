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

void dfs(int pos, int apos, int bpos, int cpos);

int N, A, B, C;
int banboo[10];
int al[10], bl[10], cl[10];
int res = INF;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> A >> B >> C;
    for(int i = 0; i < N; ++i) {
        cin >> banboo[i];
    }

    dfs(0, 0, 0, 0);
    cout << res << endl;

    return 0;
}

void dfs(int pos, int apos, int bpos, int cpos) {
    if(pos == N) {
        if(apos == 0 || bpos == 0 || cpos == 0) return;
        int asum = 0, bsum = 0, csum = 0;
        for(int i = 0; i < apos; ++i) {
            asum += al[i];
        }
        for(int i = 0; i < bpos; ++i) {
            bsum += bl[i];
        }
        for(int i = 0; i < cpos; ++i) {
            csum += cl[i];
        }

        int cost = (apos + bpos + cpos - 3) * 10;
        res = min(res, cost + abs(asum - A) + abs(bsum - B) + abs(csum - C));

        return;
    }

    al[apos] = banboo[pos]; dfs(pos + 1, apos + 1, bpos, cpos);
    bl[bpos] = banboo[pos]; dfs(pos + 1, apos, bpos + 1, cpos);
    cl[cpos] = banboo[pos]; dfs(pos + 1, apos, bpos, cpos + 1);
    dfs(pos + 1, apos, bpos, cpos);

    return;
}
