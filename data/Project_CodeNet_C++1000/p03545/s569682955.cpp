#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    vector<int> abcd(4);
    rep(i, 4) {
        char c;
        cin >> c;
        abcd[i] = (int)c-'0';
    }
    rep(i, 1<<3) {
        bitset<3> bit = i;
        int sum = abcd[0];
        vector<char> op(3);
        rep(j, 3) {
            if (bit.test(j)) {
                sum += abcd[j+1];
                op[j] = '+';
            } else {
                sum -= abcd[j+1];
                op[j] = '-';
            }
        }
        if (sum == 7) {
            rep(j, 3) {
                printf("%d%c", abcd[j], op[j]);
            }
            printf("%d=7\n", abcd[3]);
            break;
        }
    }
}