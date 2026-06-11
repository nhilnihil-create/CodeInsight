#include <bits/stdc++.h>

using namespace std;

void solve() {
    char X, Y;
    cin >> X >> Y;
    if (X < Y)
    {
        cout << "<" << endl;
    }
    else if (X > Y)
    {
        cout << ">" << endl;
    }
    else
    {
        cout << "=" << endl;
    }
}

int main() {
    solve();
    return 0;
}