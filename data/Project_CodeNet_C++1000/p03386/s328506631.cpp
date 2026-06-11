#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    set<int> s;
    for (int i = a; i < a + k && i <= b; i++) {
        s.insert(i);
    }
    for (int i = b; i > b - k && i >= a; i--) {
        s.insert(i);
    }
    for (const auto e : s) {
        cout << e << endl;
    }
}
