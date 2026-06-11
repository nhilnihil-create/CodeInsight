#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
    int h, w, n;
    int r, c;
    string s, t;
    cin >> h >> w >> n >> r >> c >> s >> t;
    int r1 = r, c1 = c;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            c1--;
        }
        if (c1 <= 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (t[i] == 'R') {
            c1 = min(w, c1 + 1);
        }
    }
    r1 = r, c1 = c;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            c1++;
        }
        if (c1 > w) {
            cout << "NO" << endl;
            return 0;
        }
        if (t[i] == 'L') {
            c1 = max(1, c1 - 1);
        }
    }
    r1 = r, c1 = c;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') {
            r1++;
        }
        if (r1 > h) {
            cout << "NO" << endl;
            return 0;
        }
        if (t[i] == 'U') {
            r1 = max(1, r1 - 1);
        }
    }
    r1 = r, c1 = c;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            r1--;
        }
        if (r1 <= 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (t[i] == 'D') {
            r1 = min(h, r1 + 1);
        }
    }
    cout << "YES" << endl;
    return 0;
}