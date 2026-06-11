#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;
    b.pop_back();
    cout << a.front();
    cout << b.back();
    cout << c.back();
}