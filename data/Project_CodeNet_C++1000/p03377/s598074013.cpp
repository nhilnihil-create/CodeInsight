#include <bits/stdc++.h>

using namespace std;

int main() {
    int A,B,X;
    cin >> A >> B >> X;

    bool res = A <= X ? (A+B >= X) : false;

    cout << (res ? "YES" : "NO") << endl;

    return 0;
}