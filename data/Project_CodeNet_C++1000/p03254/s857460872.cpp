#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, x, cnt = 0; cin >> N >> x;
    vector<int> a(N, 0);
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < N; ++i) {
        x -= a[i];
        if (i == N - 1) {
             if (x == 0) cnt++;
        }
        else {
            if (x >= 0) cnt++;
            else break;
        }
    }
    printf("%d\n", cnt);
}
