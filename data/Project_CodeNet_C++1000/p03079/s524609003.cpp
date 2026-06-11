#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (max({a, b, c}) == min({a, b, c})) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
