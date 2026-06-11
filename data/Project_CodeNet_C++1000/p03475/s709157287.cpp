#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;    
    vector<int> c(n - 1), s(n - 1), f(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> c[i] >> s[i] >> f[i];
    }

    for (int i = 0; i <= n - 1; i++) {
        int ans = 0;
        if (i != n - 1) {
            ans += s[i];
            ans += c[i];
            for (int j = i + 1; j <= n - 2 ; j++) {

                if (s[j] <= ans) {
                    int tmp = ans % f[j];
                    if (tmp != 0) {
                        ans += f[j] - tmp;
                    }
                }
                else { // ans < s[j]
                    ans += s[j] - ans;
                }
                ans += c[j];
            }
        }
        else {
            ans = 0;
        }
        cout << ans << endl;
    }

    return 0;
}