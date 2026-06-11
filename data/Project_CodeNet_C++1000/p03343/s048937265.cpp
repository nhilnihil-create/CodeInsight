#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n, k, q; cin >> n >> k >> q;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 1<<30;
    for (int i = 0; i < n; i++) {
        vector<int> ii, tmp;
        ii.push_back(-1);
        for (int j = 0; j < n; j++) if (a[j] < a[i]) ii.push_back(j);
        ii.push_back(n);
        for (int j = 1; j < ii.size(); j++) {
            if (ii[j] - ii[j-1] > k) {
                vector<int> tmp2;
                for (int m = ii[j-1]+1; m < ii[j]; m++)
                    tmp2.push_back(a[m]);
                sort(tmp2.begin(), tmp2.end());
                for (int m = 0; m + k <= tmp2.size(); m++)
                    tmp.push_back(tmp2[m]);
            }
        }
        if (tmp.size() < q) continue;
        sort(tmp.begin(), tmp.end());
        ans = min(ans, tmp[q-1] - tmp[0]);
    }
    cout << ans << endl;
}
