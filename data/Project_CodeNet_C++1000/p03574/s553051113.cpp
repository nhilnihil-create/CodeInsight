#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, cnt;
    cin >> h >> w;
    string s[h];
    for (int i=0; i<h; ++i) {
        cin >> s[i];
    }
    
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            if (s[i].at(j) == '.') {
                cnt = 0;
                for (int hi=i-1; hi<i+2; ++hi) {
                    if (hi<0||hi>=h) { continue; }
                    for (int wj=j-1; wj<j+2; ++wj) {
                        if (wj<0||wj>=w) { continue; }
                        
                        if (s[hi].at(wj) == '#') {
                            ++cnt;
                        }
                    }
                }
                s[i].at(j) = '0' + cnt;
            }
        }
    }
    
    for (int i=0; i<h; ++i) {
        cout << s[i] << endl;
    }
}