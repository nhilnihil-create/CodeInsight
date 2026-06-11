#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> map(h, vector<int>(w));
    rep(i, h) {
        rep(j, w) {
            cin >> map[i][j];
        }
    }

    // 添字を覚えておくための配列
    vector<string> index_map(h * w);
    int index = 0;

    vector<int> map2 = {};
    rep(i, h) {
        if (i % 2 == 0) {
            for (int j = 0; j < w; j++) {
                map2.push_back(map[i][j]);

                index_map[index] = to_string(i + 1) + " " + to_string(j + 1);
                index++;
            }
        } else {
            for (int j = w - 1; j >= 0; j--) {
                map2.push_back(map[i][j]);
                index_map[index] = to_string(i + 1) + " " + to_string(j + 1);
                index++;
            }
        }
    }

    vector<string> res = {};
    int res_cnt = 0;
    rep(i, h * w - 1) {
        if (map2[i] % 2 == 1) {
            res_cnt++;
            map2[i]--;
            map2[i + 1]++;

            res.push_back(index_map[i] + " " + index_map[i + 1]);
        }
    }

    cout << res_cnt << endl;
    rep(i, res.size()) {
        cout << res[i] << endl;
    }
}