#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int count = 0;
    while (b >= a && count < c) {
        b -= a;
        count++;
    }
    cout << count << endl;
}