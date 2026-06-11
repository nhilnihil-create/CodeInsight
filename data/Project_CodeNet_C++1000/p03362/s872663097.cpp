#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 55556;
int n, m, k, ans;
bool P[N];

int main() {
    fill(P, P + N, true);
    for (int i = 2; i <= N; ++i) {
        if (P[i]) {
            for (int j = i + i; j <= N; j += i) {
                P[j] = false;
            }
        }
    }
    cin >> n;
    --n;
    cout << 7 << ' ';
    for (int i = 8; i <= N; ++i) {
        if (!n) break;
        if (P[i] && i % 10 == 7) {
            --n;
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}
