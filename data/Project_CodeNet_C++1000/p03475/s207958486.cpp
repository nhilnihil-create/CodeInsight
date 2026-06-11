#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int N;
    cin >> N;

    if (N == 1) {
    } else {
        vector<int> carr(N - 1, 0);
        vector<int> sarr(N - 1, 0);
        vector<int> farr(N - 1, 0);
        for (int i = 0; i < N - 1; i++) {
            int c, s, f;
            cin >> c >> s >> f;
            carr[i] = c;
            sarr[i] = s;
            farr[i] = f;
        }

        for (int j = 1; j < N; j++) {
            int idx = j - 1;
            int64_t ans = 0;
            for (int k = idx; k < N - 1; k++) {
                if (k == idx) {
                    ans = carr[idx] + sarr[idx];
                } else {
                    //cout << "sarr[k] " << sarr[k] << endl;
                    //cout << "farr[k] " << farr[k] << endl;
                    //cout << "carr[k] " << carr[k] << endl;
                    //cout << ((ans / sarr[k]) * sarr[k]) + farr[k] + carr[k] << endl;
                    int64_t start = sarr[k];
                    if (ans > sarr[k]) {
                        if (ans % farr[k] == 0) {
                            start = ans;
                        } else {
                            start = ans + farr[k] - (ans % farr[k]);
                        }
                    }
                    //cout << "start:" << start << endl;;
                    ans = start + carr[k];
                }
                //cout << "ans:" << ans << endl;
            }
            cout << ans << endl;
        }
    }
    cout << 0 << endl;
   
    return 0;
}
