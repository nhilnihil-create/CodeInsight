#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    int a, b; cin >> a >> b;

    string s;

    if ((b - a - 1) % 2)
        s = "Alice";
    else
        s = "Borys";

    cout << s << endl;
}