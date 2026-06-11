#include <bits/stdc++.h>
using namespace std;

// g++ -std=c++17 -O2 -Wall template.cpp -o template
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << (max(a, b) < 2 * min(a, b) ? "Yay!" : ":(") << endl;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // Solution
}
