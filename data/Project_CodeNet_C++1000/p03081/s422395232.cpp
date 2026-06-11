#include <bits/stdc++.h>
using namespace std;

int N, Q;
string s;
vector<char> t, d;

int L, R;

int check(int m) {
    for (int i = 0; i < Q; i++) {
        if (t[i] == s[m]) {
            if (d[i] == 'L') {
                m--;
            } else {
                m++;
            }
            if (m == -1 || m == N) {
                return m;
            }
        }
    }
    return m;
}

int right() {
    int l = L, r = N;
    for (int i = 0; i < 30; i++) {
        int m = (l + r) / 2;
        if (check(m) == N) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}

int left() {
    int l = -1, r = N;
    for (int i = 0; i < 30; i++) {
        int m = (l + r) / 2;
        if (check(m) == -1) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    cin >> N >> Q;
    cin >> s;
    t.resize(Q);
    d.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> t[i] >> d[i];
    }
    L = left();
    R = right();
    cout << R - L - 1 << endl;
}