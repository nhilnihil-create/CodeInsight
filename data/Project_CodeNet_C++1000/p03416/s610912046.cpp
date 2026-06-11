#include <bits/stdc++.h>
using namespace std;

bool func(int n) {
    string s = to_string(n);

    bool b = true;
    for (int i = 0, n = s.size(), h = n / 2; i < h; i++)
        if (s.at(i) != s.at(n - 1 - i)) {
            b = false;
            break;
        }

    return b;
}

int main() {
    int a, b;
    cin >> a >> b;

    int cnt = 0;
    for (int i = a; i <= b; i++)
        if (func(i))
            cnt++;

    cout << cnt << endl;
}