#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
template<class T> static inline void chmax(T& a, T b) {if (a < b) { a = b; }}
int main() {
    int X; cin >> X;
    unsigned long long int ans = 1;
    bool t = false;
    for (int i = 2; i <= X; i++) {
        for (int j = 2; ; j++) {
            unsigned long long int tmp = pow(i, j);
            if (tmp > X) {
                t = true; break;
            }
            else chmax(ans, tmp);
        }
        if (t == true) {
            t = false; continue;
        }
    }
    cout << ans << endl;
}
