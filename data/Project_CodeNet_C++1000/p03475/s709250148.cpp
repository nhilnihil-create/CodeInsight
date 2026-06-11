#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    n--;
    int c[n], s[n], f[n];
    rep(i, n) cin >> c[i] >> s[i] >> f[i];

    rep(i, n) {
        int t = s[i] + c[i];
        for (int j = i + 1; j < n; j++) {
            if (t < s[j])
                t = s[j];
            else if (t % f[j] == 0)
                ;
            else
                t = t + f[j] - t % f[j];
            t += c[j];
        }
        cout << t << endl;
    }

    cout << 0 << endl;
    return 0;
}
