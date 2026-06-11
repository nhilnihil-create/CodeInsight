#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    string res;
    cin >> a >> b;
    if (a*b % 2 == 0) {
        res = "Even";
    } else {
        res = "Odd";
    }
    cout << res << endl;
    return 0;
}