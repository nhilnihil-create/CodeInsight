#include <bits/stdc++.h>
using namespace std;
int main() {
    string c[2];
    for (int i = 0; i < 2; i++)
        cin >> c[i];
    if (c[0][0] == c[1][2] && c[0][1] == c[1][1] && c[0][2] == c[1][0]) cout << "YES";
    else cout << "NO";
}