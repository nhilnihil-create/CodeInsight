#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> k(M);
    vector<vector<int>> s(M, vector<int>());
    for (int i = 0; i < M; i++) {
        cin >> k[i];
        s[i].resize(k[i]);
        for (int j = 0; j < k[i]; j++) {
            cin >> s[i][j];
        }
    }
    vector<int> p(M);
    for (int i = 0; i < M; i++) {
        cin >> p[i];
    }

    //
    //
    int count = 0;
    for (int i = 0; i < (1 << N); i++) {
        bitset<10> bs(i);
        bool ok = true;
        for (int j = 0; j < M; j++) {
            int on = 0;
            for (int l = 0; l < k[j]; l++) {
                if (bs[s[j][l] - 1]) {
                    on++;
                }
            }
            if (on % 2 != p[j]) {
                ok = false;
            }
        }
        if (ok) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
