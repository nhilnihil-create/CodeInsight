#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, n) cin >> b[i];

    vector<int> ans;
    rep(i, n) {
        int k = 0;
        int cng = -1;
        rep(j, n) {
            if (b[j] == 0) {
                continue;
            }
            if (b[j] == k + 1) {
                cng = j;
            }
            k++;
        }
        // cout << i << " " << cng << endl;
        if (cng == -1) {
            puts("-1");
            return 0;
        }
        ans.push_back(b[cng]);
        b[cng] = 0;
    }
    rep(i, n) {
        cout << ans[n - i - 1] << endl;
    }
}