#include "bits/stdc++.h"

using namespace std;

void Main() {
    string S;
    cin >> S;
    int A, B, C, D;
    vector<int> abcd(4, 0);
    abcd[0] = (int)(S[0] - '0');
    abcd[1] = (int)(S[1] - '0');
    abcd[2] = (int)(S[2] - '0');
    abcd[3] = (int)(S[3] - '0');

    for (int bit = 0; bit < (1 << 3); ++bit) {
        bitset<3> b(bit);
        int eq = abcd[0];
        vector<string> ops(3, "");
        for (int i = 1; i <= 3; ++i) {
            if (b[i - 1]) {
                eq += abcd[i];
                ops[i - 1] = "+";
            }
            else {
                eq -= abcd[i];
                ops[i - 1] = "-";
            }
        }
        if (eq == 7) {
            string ans = to_string(abcd[0]) + ops[0]
                + to_string(abcd[1]) + ops[1]
                + to_string(abcd[2]) + ops[2]
                + to_string(abcd[3]) + "=7";
            cout << ans << endl;
            return;
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
