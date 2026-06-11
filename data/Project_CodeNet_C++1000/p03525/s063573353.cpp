#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int N; cin >> N;
    vector<int> D(N); for (auto &d : D) cin >> d;
    vector<int> C(13);
    for (auto d : D) {
        C[d]++;
    }
    vector<bool> X(24);
    X[0] = true;
    auto recur = [&](auto rec, int i) {
        if (i == 13) {
            int j = 0, k = 1, ans = 999;
            while (j < 24) {
                while (k < 24 && X[k] == false) k++;
                ans = min(ans, k - j);
                j = k, k += 1;
            }
            return ans;
        } else if (C[i] == 0) {
            return rec(rec, i+1);
        } else if (C[i] == 1) {
            int ans = 0;
            if (!X[i]) {
                X[i] = true;
                ans = max(ans, rec(rec, i+1));
                X[i] = false;
            }
            if (i != 0 && !X[24-i]) {
                X[24-i] = true;
                ans = max(ans, rec(rec, i+1));
                X[24-i] = false;
            }
            return ans;
        } else if (C[i] == 2) {
            if (X[i] || X[24-i]) {
                return 0;
            }
            X[i] = X[24-i] = true;
            int ans = rec(rec, i+1);
            X[i] = X[24-i] = false;
            return ans;
        } else {
            return 0;
        }
    };
    cout << recur(recur, 0) << '\n';
    return 0;
}