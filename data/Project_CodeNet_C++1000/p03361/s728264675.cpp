#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++)
        cin >> s.at(i);
    bool tf = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s.at(i).at(j) == '#') {
                bool ijnotpaint = true;
                if(i - 1 >= 0) {
                    if (s.at(i - 1).at(j) == '#') continue;
                }
                if (i + 1 < h) {
                    if (s.at(i + 1).at(j) == '#') continue;
                }
                if(j - 1 >= 0) {
                    if (s.at(i).at(j - 1) == '#') continue;
                }
                if (j + 1 < w) {
                    if (s.at(i).at(j + 1) == '#') continue;
                }
                if (ijnotpaint){
                    tf = false;
                    break;
                }
            }
        }
        if (!tf) break;
    }
    if (tf) cout << "Yes" << endl;
    else cout << "No" << endl;
}