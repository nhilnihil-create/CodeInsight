#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m, vector<int>(0));
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int num;
            cin >> num;
            s[i].push_back(num);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    int cnt = 0;
    for (int tmp = 0; tmp < (1 << n); tmp++) {
        bitset<10> bit(tmp);
        int on = 0;
        bool flag = true;
        for (int j = 0; j < m; j++) {
            on = 0;
            for (int l = 0; l < (int)s[j].size(); l++) {
                if (bit.test(s[j][l] - 1)) {
                    on++;
                }
            }
            if (on % 2 != p[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
