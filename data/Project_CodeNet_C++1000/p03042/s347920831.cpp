#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int a;
    cin >> a;
    int b = a/100;
    int c = a%100;

    if (1 <= b && b <= 12) {
        if (1 <= c && c <= 12) cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    } else {
        if (1 <= c && c <= 12) cout << "YYMM" << endl;
        else cout << "NA" << endl;
    }
    return 0;
}
