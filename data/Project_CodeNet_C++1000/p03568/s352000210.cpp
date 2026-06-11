#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

int intpow(int a, int b) {
    int tmp = 1;
    REP(i, b) tmp *= a;
    return tmp;
}

int main() {
    int n; cin >> n;
    int even = 0;
    REP(i, n) {
        int tmp; cin >> tmp;
        if (tmp % 2 == 0) ++even;
    }

    cout << intpow(3, n) - intpow(2, even) << endl;

    return 0;
}