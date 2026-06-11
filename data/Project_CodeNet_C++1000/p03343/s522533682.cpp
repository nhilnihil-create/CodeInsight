#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = (int)1e9 + 7;

int main() {
    int n, k; cin >> n >> k;
    int q; cin >> q;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    a.emplace_back(-INF);
    int mi = INF;
    for (int min_i = 0; min_i < n; min_i++) {
        vector<int> cand, tmp;
        for (int i = 0; i < n + 1; i++) {
            if (a[i] < a[min_i]) {
                if ((int)tmp.size() >= k) {
                    sort(begin(tmp), end(tmp));
                    for (int _ = 0; _ < k - 1; _++) tmp.pop_back();
                    cand.insert(cand.end(), tmp.begin(), tmp.end());
                }
                tmp.clear();
            } else {
                tmp.emplace_back(a[i]);
            }
        }
        if ((int)cand.size() >= q) {
            sort(begin(cand), end(cand));
            mi = min(mi, cand[q - 1] - cand[0]);
        }
    }
    cout << mi << endl;
    return 0;
}
