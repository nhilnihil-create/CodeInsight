#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> p;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        if (p.count(tmp)) {
            p[tmp]++;
        } else {
            p[tmp] = 1;
        }
    }

    int m = 0;
    vector<int> cnts = {};
    for (auto q : p) {
        m++;
        cnts.push_back(q.second);
    }

    if (m <= k) {
        cout << 0 << endl;
    } else {
        sort(cnts.begin(), cnts.end());
        int replace_cnt = 0;
        rep(i, m - k) {
            replace_cnt += cnts[i];
        }

        cout << replace_cnt << endl;
    }
}