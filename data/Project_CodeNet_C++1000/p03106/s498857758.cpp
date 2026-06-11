#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, n) for (int i = 1; i <= (n); ++i)

int main() {
    int a, b, k;
    vector<int> ans;
    cin >> a >> b >> k;
    int n = max(a, b);
    rep2(i, n) {
        if (a % i == 0 && b % i == 0) {
            ans.push_back(i);
        }
    }

    cout << ans[ans.size() - k] << endl;
    return 0;
}