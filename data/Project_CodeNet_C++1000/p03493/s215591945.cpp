#include <bits/stdc++.h>
using namespace std;

int main() {
    int s;
    cin >> s;
    int c1 = s / 100;
    int c2 = s % 100 / 10;
    int c3 = s % 10;
    cout << c1 + c2 + c3 << endl;
}