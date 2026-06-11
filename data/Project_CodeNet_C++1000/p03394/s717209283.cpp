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
    int n;
    cin >> n;
    if (n == 3) {
        cout << "2 5 63" << endl;
        return 0;
    }
    if (n == 4) {
        cout << "2 5 20 63" << endl;
        return 0;
    }
    if (n == 6) {
        cout << "2 3 4 5 6 10" << endl;
        return 0;
    }
    n -= 5;
    long long co = 0;
    int w = 2, h = 3;
    bool b = true;
    for (int i = 0; i < 5000; i++) {
        int m = n - i * 3;
        if (m % 2 == 0 && m >= 0 && m < 5000) {
            h += i * 3;
            w += m;
            b = false;
            break;
        }
    }
    if (b) {
        for (int i = 2; i < 15000; i += 3) {
            int m = n - i;
            if (m % 2 == 0 && m >= 0 && m < 5000) {
                h += i;
                w += m;
                break;
            }
        }
    }
    int ans = 3;
    for (int i = 0; i < w; i++) {
        cout << ans << " ";
        ans += 6;
    }
    ans = 2;
    for (int i = 0; i < h; i++) {
        cout << ans;
        if (i != h - 1) {
            cout << " ";
        }
        ans += 2;
    }
    cout << endl;
}