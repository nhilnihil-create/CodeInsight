#include <bits/stdc++.h>
using namespace std;
int main () {
    int a = 0;
    string s;
    cin >> s;
    for (auto x: s) {
        if (x == '2') a++;
    }
    cout << a << endl;
}