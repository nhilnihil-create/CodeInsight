#include <bits/stdc++.h>
using namespace std;

int main() {
    int s;
    int a, b;
    cin >> s;

    a = s / 100;
    b = s % 100;

    if (1 <= a && a <= 12) {
        if (1 <= b && b <= 12) cout << "AMBIGUOUS" << "\n";
        else cout << "MMYY" << "\n";
    } else {
        if (1 <= b && b <= 12) cout << "YYMM" << "\n";
        else cout << "NA" << "\n";
    }
}