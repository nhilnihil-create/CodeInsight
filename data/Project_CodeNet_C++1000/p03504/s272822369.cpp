#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;

int main() {
    const int maxT = 1E+5 + 10;

    int N, C;
    cin >> N >> C;
    vector<vector<int>> record;
    record.assign(maxT, vector<int>(C+1, 0));

    int si, ti, ci, maxTi = 0;
    rep(i, N) {
        cin >> si >> ti >> ci;
        record[si][ci] = 2;
        record[ti][ci] = max(record[ti][ci], 1);
        maxTi = max(maxTi, ti);
    }

    for (int c=0; c<=C; c++) {
        bool recording = false;
        for (int t=0; t<=maxTi; t++) {
            if (record[t][c] == 2) recording = true;
            else if (record[t][c] == 1) recording = false;

            if (recording) record[t][c] = 2;
        }
    }


    int ans = 0;
    for (int t=0; t<=maxTi; t++) {
        int num_t = 0;
        for (int c=0; c<=C; c++) {
            // cout << record[t][c] << " ";
            if (record[t][c] > 0) num_t += 1;
        }
        // cout << endl;
        ans = max(ans, num_t);
    }

    cout << ans << endl;

    return 0;
}

