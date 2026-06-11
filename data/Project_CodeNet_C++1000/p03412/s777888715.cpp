#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define INF 1e9
#define LINF 1e18

const int MOD = 1e9 + 7;
const int dy[]={0, 0, 1, -1};
const int dx[]={1, -1, 0, 0};

typedef pair<int, int> P;
typedef pair<P, int> Pi;
typedef pair<P, P> PP;

template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

int a[200000], b[200000];
int at[200000], bt[200000];
int N;

int solve() {
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> a[i];
    for(int i = 0; i < N; ++i) cin >> b[i];
    sort(b, b + N);
    int res = 0;
    for(int i = 0; i < 29; ++i) {
        int even = 0;
        for(int j = 0; j < N; ++j) {
            at[j] = a[j] % (1 << (i + 1));
            bt[j] = b[j] % (1 << (i + 1));
        }
        sort(bt, bt + N);
        for(int j = 0; j < N; ++j) {
            if(at[j] & (1 << i)) {
                even += lower_bound(bt, bt + N, (1 << (i + 1)) - at[j]) - bt;
                even += (bt + N) - lower_bound(bt, bt + N, (3 << i) - at[j]);
            }
            else {
                even += lower_bound(bt, bt + N, (1 << (i + 1)) - at[j]) - lower_bound(bt, bt + N, (1 << i) - at[j]);
            }
        }
        res ^= ((even&1) << i);
    }
    return res;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << solve() << endl;
    return 0;
}