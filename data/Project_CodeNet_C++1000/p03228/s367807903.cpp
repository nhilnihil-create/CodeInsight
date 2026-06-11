#include <iostream>
using namespace std;
int main() {
    int a, b, k;
    cin >> a >> b >> k;
    for (int i = 0; i < k; ++i) {
        auto &from = (i % 2 == 0 ? a : b);
        auto &to = (i % 2 == 0 ? b : a);
        if (from % 2 == 1) {
            --from;
        }
        from /= 2;
        to += from;
    }
    cout << a << ' ' << b << '\n';
}