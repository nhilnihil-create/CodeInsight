#include <iostream>
using namespace std;
int main() {
    int s;
    cin >> s;
    int kami2, shimo2;
    kami2 = s / 100;
    shimo2 = s % 100;
    if (kami2 > 0 && kami2 < 13) {
        if (shimo2 > 0 && shimo2 < 13) {
            cout << "AMBIGUOUS" << endl;
        } else {
            cout << "MMYY" << endl;
        }
    } else {
        if (shimo2 > 0 && shimo2 < 13) {
            cout << "YYMM" << endl;
        } else {
            cout << "NA" << endl;
        }
    }
}