#include <bits/stdc++.h>
using namespace std;

int main() {
    int a=0, b=0;
    char c;

    cin >> c; a = (c-'0')*10; cin >> c; a += c-'0';
    cin >> c; b = (c-'0')*10; cin >> c; b += c-'0';

    if (1 <= a && a <= 12 && 1 <= b && b <= 12) {
        cout << "AMBIGUOUS";
    } else if (1 <= a && a <= 12) {
        cout << "MMYY";
    } else if (1 <= b && b <= 12) {
        cout << "YYMM";
    } else {
        cout << "NA";
    }

    return 0;
}
