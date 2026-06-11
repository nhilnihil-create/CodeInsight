#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MOD = (int)1e9 + 7;

int main() {
    string s; cin >> s;
    long long _ = 1, a = 0, ab = 0, abc = 0;
    for (char ch: s) {
        if (ch == 'A') a += _;
        if (ch == 'B') ab += a;
        if (ch == 'C') abc += ab;
        if (ch == '?') {
            abc = abc * 3 + ab;
            ab = ab * 3 + a;
            a = a * 3 + _;
            _ = _ * 3;
        }
        _ %= MOD, a %= MOD, ab %= MOD, abc %= MOD;
    }
    cout << abc << endl;
    return 0;
}
