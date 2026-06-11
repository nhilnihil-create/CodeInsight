#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int N, Y; cin >> N >> Y;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i + j > N) continue;

            int k = N - i - j;
            if (k < 0) continue;

            int m = 10000 * i + 5000 * j + 1000 * k;
            if (m == Y) {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}
