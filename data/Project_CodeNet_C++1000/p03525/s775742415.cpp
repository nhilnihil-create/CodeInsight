#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ALL(c) (c).begin(), (c).end()
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    set<int> s;
    s.insert(0);
    int d;
    for (int i = 0; i < n; i++) {
        cin >> d;
        if (d == 0) {
            cout << 0 << endl;
            return 0;
        }
        if (s.count(d) == 1) {
            if (s.count(24 - d) == 1) {
                cout << 0 << endl;
                return 0;
            } else {
                s.insert(24 - d);
            }
        } else {
            s.insert(d);
        }
    }

    vector<int> x(25, 0);
    x[0] = 1;
    x[24] = 1;
    bool left = true;
    for (const int h : s) {
        if (h > 12) {
            break;
        }
        if (h == 12) {
            x[h] = 1;
        } else if (s.count(24 - h) == 0) {
            if (left) {
                x[h] = 1;
                left = false;
            } else {
                x[24 - h] = 1;
                left = true;
            }
        } else {
            x[h] = 1;
            x[24 - h] = 1;
            left = true;
        }
    }

    int mn = 12;
    int c = 1;
    for (int i = 1; i <= 24; i++) {
        if (x[i] == 1) {
            mn = min(mn, c);
            c = 1;
        } else {
            c++;
        }
    }

    cout << mn << endl;
}
