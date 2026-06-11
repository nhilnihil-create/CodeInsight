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

const int N = 100;
int a, b;
char ans[N][N];
// h, w <= 100
int main() {
    cin >> a >> b;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j < 50)
                ans[i][j] = '.';
            else
                ans[i][j] = '#';
        }
    }
    a--; b--;
    if (a) {
        for (int i = 0; i < N; i += 2) {
            for (int j = 51; j < N; j += 2) {
                ans[i][j] = '.';
                --a;
                if (!a)
                    break;
            }
            if (!a)
                break;
        }
    }
    if (b) {
        for (int i = 0; i < N; i += 2) {
            for (int j = 0; j < 50; j += 2) {
                ans[i][j] = '#';
                --b;
                if (!b)
                    break;
            }
            if (!b)
                break;
        }
    }
    cout << N << ' ' << N << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
