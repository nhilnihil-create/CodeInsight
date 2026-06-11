#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    long long int A, B, C, ans = 0; cin >> A >> B >> C;
    if (A < C) ans += A, C -= A;
    else ans += C, C = 0;
    if (B >= C) ans += B + C;
    else ans += 2 * B + 1;
    printf("%d\n", ans);
}
