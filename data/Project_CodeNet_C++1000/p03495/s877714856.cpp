#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k; cin >> n >> k;
    map<int, int> a;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }
    vector<int> c;
    for (auto p : a) {
        c.push_back(p.second);
    }

    sort(c.begin(), c.end());
    int ans = 0;
    if (c.size() <= k) puts("0");
    else {
        for(int i = 0; i < c.size()-k; i++) {
            ans += c[i];
        }
        cout << ans << endl;
    }
}