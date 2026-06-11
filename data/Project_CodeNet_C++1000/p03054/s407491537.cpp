#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n, sr, sc;
    cin >> h >> w >> n >> sr >> sc;
    string s, t;
    cin >> s >> t;

    int nowU = sr, nowD = sr, nowL = sc, nowR = sc;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'U') {
            if (nowU == 1) {
                cout << "NO" << endl;
                return 0;
            }
            else nowU--;
        }
        else if (s.at(i) == 'D') {
            if (nowD == h) {
                cout << "NO" << endl;
                return 0;
            }
            else nowD++;
        }
        else if (s.at(i) == 'L') {
            if (nowL == 1) {
                cout << "NO" << endl;
                return 0;
            }
            else nowL--;
        }
        else if (s.at(i) == 'R') {
            if (nowR == w) {
                cout << "NO" << endl;
                return 0;
            }
            else nowR++;
        }

        if (t.at(i) == 'U') {
            nowD = max(1, nowD - 1);
        }
        else if (t.at(i) == 'D') {
            nowU = min(h, nowU + 1);
        }
        else if (t.at(i) == 'L') {
            nowR = max(1, nowR - 1);
        }
        else if (t.at(i) == 'R') {
            nowL = min(w, nowL + 1);
        }
    }

    cout << "YES" << endl;
}