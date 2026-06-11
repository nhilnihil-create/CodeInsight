#include <bits/stdc++.h>
using namespace std;

// g++ -std=c++17 -O2 -Wall template.cpp -o template
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    unsigned long long l = 0;
    for (int i = 1; i < b - a; i++) {
        l += i;
    }
    cout << l - a << endl;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // Solution
}
