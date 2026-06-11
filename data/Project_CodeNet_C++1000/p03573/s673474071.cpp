#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    if (a != b && a != c)
        cout << a;
    else if (b != a && b != c)
        cout << b;
    else
        cout << c;
}