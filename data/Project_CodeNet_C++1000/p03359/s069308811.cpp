#include "bits/stdc++.h"

using namespace std;

void Main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if (b < a) {
        ans = a - 1;
    }
    else {
        ans = a;
    }
    cout << ans << endl;;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
