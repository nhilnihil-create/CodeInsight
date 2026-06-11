#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define rep(i, n) for (int i{ 0 }; i < n; ++i)

using namespace std;

int main() {
    int i_s;
    cin >> i_s;
    vector<int> v(4);

    rep(i, 4) {
        v.at(3 - i) = i_s % 10;
        i_s = (i_s - v.at(3 - i)) / 10;
    }

    // printf("%d %d %d %d", a,b,c,d);

    rep(i, 1 << 3) {
        int tmp = v.at(0);
        string s[3];

        rep(j, 3) {
            if (i & 1 << j) {
                tmp += v.at(j + 1);
                s[j] = '+';
            } else {
                tmp -= v.at(j + 1);
                s[j] = '-';
            }
        }
        if (tmp == 7) {
            printf("%d%s%d%s%d%s%d=7\n", v[0], s[0].data(), v[1], s[1].data(), v[2], s[2].data(), v[3]);
            break;
        }
    }
}
