#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, n, p1, p2;
    cin >> n >> a >> b;
    p1 = a*n;
    p2 = b;
    if (p1 > p2) {
        cout << p2 << endl;
    } else {
        cout << p1 << endl;
    }
    return 0;
}