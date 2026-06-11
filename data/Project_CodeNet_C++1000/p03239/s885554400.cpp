#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, T, ans = 10e6; cin >> N >> T;
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        if (b <= T) ans = min(ans, a);
    }
    if (ans != 10e6) printf("%d\n", ans);
    else printf("%s\n", "TLE");
}
