#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    if (n % 2 == 0) return n / 2;
    else return 3 * n + 1;
}

int main() {
    int s;
    cin >> s;

    set<int> S;
    S.insert(s);

    for (int i = 1; i <= 1e6; i++) {
        s = f(s);
        if (S.count(s)) {
            cout << i + 1 << endl;
            return 0;
        } else {
            S.insert(s);
        }
    }
}