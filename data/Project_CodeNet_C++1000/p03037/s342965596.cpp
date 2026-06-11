// 有點不耐煩會破壞偉大的計劃

#include <bits/stdc++.h>

#define append push_back

using namespace std;
using ll = long long;

const int N = 1e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e14 + 9;
const int SM = 1e3 + 5;
const int logN = 22, BL = 400;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {1, 0, 0, -1, -1, 1, -1, 1};
const int dy[] = {0, 1, -1, 0, -1, 1, 1, -1};

void debug() {
	cerr << "\n";
}
template<typename Type1, typename... Type2>
void debug(Type1 a, Type2... b) {
    cerr << a << " ";
    debug(b...);
}

long long t[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n, m; cin >> n >> m;

    for(long long i = 0; i < m; i++) {
        long long l, r; cin >> l >> r;
        t[l]++, t[r + 1]--;
    }

    long long ans = 0;
    for(long long i = 1; i < N; i++) {
        t[i] += t[i - 1];
        if(t[i] == m) ans++;
    }

    cout << ans;

    return 0;
}
