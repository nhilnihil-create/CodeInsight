#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    vector<int> b(n);
    for (auto i = 0; i < n; i++) cin >> b[i];

    vector<int> ans(n, 0);
    for (auto i = 0; i < n; i++) {
        auto tmp = 0;
        for (auto j = (int)b.size() - 1; j >= 0; j--) {
            if(b[j] == j + 1) {
                tmp = j + 1; break;
            }
        }
        if(tmp == 0) {
            cout << "-1" << endl;
            return 0;
        }
        b.erase(b.begin() + (tmp - 1));
        ans[n - i - 1] = tmp;
    }

    for (auto i = 0; i < n; i++) cout << ans[i] << endl;
    return 0;
}