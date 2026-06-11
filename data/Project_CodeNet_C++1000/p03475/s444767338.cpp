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

const int N = 510;
int n;
int c[N], s[N], f[N], ans[N];

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> c[i] >> s[i] >> f[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int j = i;
        int t = 0;
        while (j < n - 1) {
            if (t <= s[j])
                t = s[j] + c[j];
            else {
                int d = t % f[j];
                if (d)
                    t += f[j] - d;
                t += c[j];
            }
            ++j;
        }
        cout << t << endl;
    }
    cout << 0 << endl;

    return 0;
}
