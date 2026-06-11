#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    int a = 0;
    for (auto &&i : to_string(x)) {
        a += i - '0';
    }
    return a;
}

int main(void) {
    string n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 1; i <= stoi(n); i++) {
        int x = f(i);
        if (a <= x && x <= b) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}