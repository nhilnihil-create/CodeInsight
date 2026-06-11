#include <bits/stdc++.h>
using namespace std;

int x[4] = {2, 3, 4, 6};

int main() {
    int n; cin >> n;
    if (n == 3) printf("%d %d %d\n", 2, 5, 63);
    else if (n == 4) printf("%d %d %d %d\n", 2, 5, 20, 63);
    else if (n == 5) printf("%d %d %d %d %d\n", 2, 5, 20, 30, 63);
    else {
        vector<int> ans(n);
        int sum = 0;
        for (int i = 0; i < n; i += 4) {
            for (int j = 0; j < 4; j++) {
                if (i+j < n) {
                    ans[i+j] = 6 * (i / 4) + x[j];
                    sum = (sum + ans[i+j]) % 6;
                }
            }
        }
        if (sum == 0) {
            for (int i = 0; i < n; i++) cout << ans[i] <<  " "; cout << "\n";
        }
        else if (sum == 2) {
            for (int i = 0; i < n; i++) if (ans[i] != 8) cout << ans[i] <<  " ";
            cout << 30000 << "\n";
        }
        else if (sum == 3) {
            for (int i = 0; i < n; i++) if (ans[i] != 9) cout << ans[i] <<  " ";
            cout << 30000 << "\n";
        }
        else if (sum == 5) {
            for (int i = 0; i < n; i++) if (ans[i] != 9) cout << ans[i] <<  " ";
            cout << 29998 << "\n";
        }
    }
    return 0;
}