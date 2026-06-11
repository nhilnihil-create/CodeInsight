#include <bits/stdc++.h>
using namespace std;

int main() {
    int  T, X;
    cin >> T >> X;
    cout << (X%T == 0? T+X:X-T);
    return 0;
}