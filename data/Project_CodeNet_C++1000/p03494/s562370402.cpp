#include <iostream>
using namespace std;
#define rep(i, j, n) for(int i = j; i < (int)n; ++i)

int main() {
    int n, a; cin >> n;
    int b = 0;
    rep(i, 0, n) {
        cin >> a;
        b |= a;
    }
    cout << __builtin_ctz(b) << endl;
}