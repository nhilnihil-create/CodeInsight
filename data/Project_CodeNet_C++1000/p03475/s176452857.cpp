#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

// 時点 start から 時点 per おきに起こる事象がある，
// 現在の時点が now の時，次にその事象が起こる時点はいくつか．
Int NextPoint(Int start, Int per, Int now) {
    now = max(start, now);
    if (now % per != 0) {
        now += (per - (now % per));
    }
    return now;
}

int main(void) {
    Int n;
    cin >> n;
    vector<Int> c(n);
    vector<Int> s(n);
    vector<Int> f(n);
    for (Int i = 0; i < n; ++i) {
        cin >> c[i] >> s[i] >> f[i];
    }
    Int t;
    for (Int i = 0; i < n; ++i) {
        t = 0;
        for (Int j = i; j < n - 1; ++j) {
            t = NextPoint(s[j], f[j], t);
            t += c[j];
        }
        cout << t << endl;
    }
    return 0;
}

