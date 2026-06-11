#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(13);
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        v[d]++;
    }

    if (v[0] > 0)cout << 0 << endl;
    else {
        vector<bool> exist(24);
        exist[0] = true;
        vector<int> alone;
        for (int i = 1; i <= 12; i++) {
            if (v[i] > 2) {
                cout << 0 << endl;
                return 0;
            } else if (v[i] == 2) {
                exist[i] = true, exist[24 - i] = true;
            } else if (v[i] == 1) {
                alone.push_back(i);
            }
        }

        int m = alone.size();
        int ret = 0;
        for (int i = 0; i < 1 << m; i++) {
            vector<bool> now = exist;
            for (int j = 0; j < m; j++) {
                if (i & (1 << j))now[alone[j]] = true;
                else now[24 - alone[j]] = true;
            }

            int nowres = 114514;
            for (int j = 0; j < 24; j++) {
                for (int k = j + 1; k < 24; k++) {
                    if (now[j] && now[k])nowres = min({nowres, k - j, 24 - (k - j)});
                }
            }
            ret = max(ret, nowres);
        }
        cout << ret << endl;
    }
    return 0;
}