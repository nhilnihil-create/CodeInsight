#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a - b) & 1) {
        puts("Borys");
    } else {
        puts("Alice");
    }
}