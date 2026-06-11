#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e9
#define LINF 1e18

typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> Pi;
typedef pair<P, P> PP;

const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

int N, a[100000];

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; ++i) cin >> a[i];
    sort(a, a + N);
    int latte = a[N - 1], malta = a[0];
    for(int i = 0; i < N - 1; ++i) {
        if(abs(a[i] - a[N - 1] / 2) <= abs(malta  - a[N - 1] / 2)) malta = a[i];
    }
    cout << latte << " " << malta << endl;
    return 0;
}