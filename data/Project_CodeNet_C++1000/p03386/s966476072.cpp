#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int a, b, k; cin >> a >> b >> k;
    if (b - a + 1 <= 2 * k) {
        for (int i = a; i <= b; i++) {
            printf("%d\n", i);
        }
    } else {
        for (int i = a; i <= a + k - 1; i++) {
            printf("%d\n", i);
        }
        for (int i = b - k + 1; i <= b; i++) {
            printf("%d\n", i);
        }
    }
    return 0;
}