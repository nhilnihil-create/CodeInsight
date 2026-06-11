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

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n, m; cin >> n >> m;

    vector<long long> votes(m);

    for(long long i = 0; i < n; i++) {
        long long k; cin >> k;
        for(long long j = 0; j < k; j++) {
            long long x; cin >> x;
            x--;
            votes[x]++;
        }
    }

    long long ans = 0;
    for(long long i = 0; i < m; i++) {
        ans += votes[i] == n;
    }

    cout << ans;

    return 0;
}
