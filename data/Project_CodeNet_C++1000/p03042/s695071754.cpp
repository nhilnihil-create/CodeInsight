#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int s;
    cin >> s;

    int a = s / 100;
    int b = s % 100;

    if (1 <= a && a <= 12) {
        if (1 <= b && b <= 12) {
            cout << "AMBIGUOUS" << endl;
        } else {
            cout << "MMYY" << endl;
        }
    } else {
        if (1 <= b && b <= 12) {
            cout << "YYMM" << endl;
        } else {
            cout << "NA" << endl;
        }
    }

    return 0;
}