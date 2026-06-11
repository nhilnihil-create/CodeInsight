#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    int N;
    cin >> N;
    vector<int> D(N);
    rep(i, N) cin >> D[i];

    vector<int> cnt(13);
    cnt[0]++;
    rep(i, N) cnt[D[i]]++;

    // 同じDが3つ以上あれば s = 0
    // D = 0, 12 は2つだけで s = 0
    for (int D = 0; D < 13; D++) {
        if ((D == 0 || D == 12) && cnt[D] >= 2) {
            cout << 0 << endl;
            return 0;
        } else if (cnt[D] >= 3) {
            cout << 0 << endl;
            return 0;
        }
    }

    int ans = 0, s;
    for (int bit = 0; bit < 1 << 13; bit++) {
        s = 12;
        vector<bool> time = vector<bool>(25, false);
        time[0] = true;
        time[24] = true;
        for (int D = 1; D < 13; D++) {
            if (cnt[D] == 2) {
                // 同じDが2個) 常に D, 24-D の2つを使用
                time[D] = true;
                time[24 - D] = true;
            } else if (cnt[D] == 1) {
                if (bit >> D & 1) {
                    // 同じDが1個) ビットが立っていれば 24-D を使用
                    time[24 - D] = true;
                } else {
                    time[D] = true;
                }
            }
        }
        vector<int> time_list;
        rep(D, 25) if (time[D]) time_list.push_back(D);
        for (int i = 0; i < time_list.size() - 1; i++) {
            s = min(s, time_list[i + 1] - time_list[i]);
        }
        ans = max(ans, s);
    }
    cout << ans << endl;
    return 0;
}