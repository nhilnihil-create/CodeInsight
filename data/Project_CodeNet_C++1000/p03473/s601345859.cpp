#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    static const int DAY_TIME = 24;

    cin >> m;

    cout << (DAY_TIME - m) + DAY_TIME << endl;
}