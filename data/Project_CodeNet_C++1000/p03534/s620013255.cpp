#include <cmath>
#include <iostream>
using namespace std;
int main() {
    string s; cin >> s;
    int a = 0, b = 0, c = 0;
    for (char x : s) { if (x == 'a') a++; else if (x == 'b') b++; else c++; }
    cout << (abs(a-b) <= 1 && abs(b-c) <= 1 && abs(c-a) <= 1 ? "YES\n" : "NO\n");
}
