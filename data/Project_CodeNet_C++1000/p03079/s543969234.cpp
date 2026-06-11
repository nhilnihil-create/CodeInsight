#include <iostream>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    printf("%s\n", (a == b && b == c) ? "Yes" : "No");
}

int main() {
    solve();
    return 0;
};


