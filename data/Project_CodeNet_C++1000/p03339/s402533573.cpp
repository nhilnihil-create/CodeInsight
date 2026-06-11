#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // int min_c = 1e6;
    // rep(i, n) {
    //     int count = 0;
    //     rep(j, n) {
    //         if (j < i) {
    //             if (s[j] == 'W') {
    //                 count++;
    //             }
    //         } else if (i < j) {
    //             if (s[j] == 'E') {
    //                 count++;
    //             }
    //         }
    //     }
    //     min_c = min(min_c, count);
    // }
    // cout << min_c << endl;
    vector<int> west(n);
    vector<int> east(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            if (i == 0) {
                west[i] = 1;
            } else {
                west[i] = west[i-1] + 1;
            }
        } else {
            west[i] = west[i-1];
        }
        if (s[n-1-i] == 'E') {
            if (i == 0) {
                east[n-1-i] = 1;
            } else {
                east[n-1-i] = east[n-i] + 1;
            }
        } else {
            east[n-1-i] = east[n-i];
        }
    }
    int min_c = 1e9;
    rep(i, n) {
        if (i == 0) {
            min_c = min(min_c, east[i+1]);
        } else if (i == n-1) {
            min_c = min(min_c, west[i-1]);
        } else {
            min_c = min(min_c, west[i-1] + east[i+1]);
        }
    }
    cout << min_c << endl;
}