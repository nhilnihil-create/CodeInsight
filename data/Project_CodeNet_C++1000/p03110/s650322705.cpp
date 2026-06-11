#include <iostream>

int main() {
    int t;
    std :: cin >> t;
    long double ans = 0;

    while(t--) {
        long double val;
        std :: string cur;

        std :: cin >> val >> cur;

        if(cur == "BTC") ans += val * 380000.0f;
        else ans += val;
    }

    std :: cout << ans << '\n';
}