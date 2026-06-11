#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    int n;
    int m;
    int x;
    cin >> n >> m >> x;
    int a[m];

    rep(i, m) { cin >> a[i]; }

    int score1 = 0;
    int score2 = 0;
    for (int i = x; i < n + 1; i++) {
        rep(j, m) {
            if (i == a[j]) {
                score1++;
            }
        }
    }

    for (int i = x; i > -1; i--) {
        rep(j, m) {
            if (i == a[j]) {
                score2++;
            }
        }
    }

    cout << min(score1, score2) << endl;
}