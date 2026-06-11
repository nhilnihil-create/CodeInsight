#include <bits/stdc++.h>
using namespace std;

int main() {
    int s;
    cin >> s;
    int a = s / 100;
    int b = (s - a * 100) / 10;
    int c = s - a * 100 - b * 10;
    cout << a + b + c << endl;
}