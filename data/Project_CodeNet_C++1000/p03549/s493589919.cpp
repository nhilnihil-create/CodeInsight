#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t N,M;
    int64_t testnum;
    cin >> N >> M;

    testnum = 1 << M;
    // 2^M回の試行
    // M*1900*試行
    // (N-M)*100*試行
    cout << (M*1900*testnum) + ((N-M)*100*testnum) << "\n";

    return 0;
}
