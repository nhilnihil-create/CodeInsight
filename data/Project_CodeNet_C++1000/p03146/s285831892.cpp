#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int s; cin >> s;
    vector<int> a(10e5, 0);
    a[0] = s;
    int ans = 0;
    if (s == 4 || s == 2 || s == 1) {
        printf("%d\n", 4);
        return 0;
    }
    for (int i = 1; i < 100000; ++i) {
        if (a[i - 1] % 2 == 0) a[i] = a[i - 1] / 2;
        else a[i] = a[i - 1] * 3 + 1;
        if (a[i] == 4) {
            ans = i + 1; break;
        }
        if (a[i] == 2) {
            ans = i; break;
        }
        if (a[i] == 1) {
            ans = i - 1; break;
        }
    }
    printf("%d\n", ans + 3);
    return 0;
}
