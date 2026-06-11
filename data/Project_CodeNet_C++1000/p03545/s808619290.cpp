#include <bits/stdc++.h>
using namespace std;

int main() {
    char a, b, c, d; cin >> a >> b >> c >> d;
    int A, B, C, D;
    A = a - '0';
    B = b - '0';
    C = c - '0';
    D = d - '0';
    vector<int> ans(8);
    ans.at(0) = A + B + C + D;
    ans.at(1) = A + B + C - D;
    ans.at(2) = A + B - C + D;
    ans.at(3) = A - B + C + D;
    ans.at(4) = A + B - C - D;
    ans.at(5) = A - B - C + D;
    ans.at(6) = A - B + C - D;
    ans.at(7) = A - B - C - D;
    for (int i = 0; i < 8; i++) {
        if (ans.at(i) == 7) {
            switch (i) {
                case 0:
                    cout << A << "+" << B << "+" << C << "+" << D << "=7" << endl;
                    break;
                case 1:
                    cout << A << "+" << B << "+" << C << "-" << D << "=7" << endl;
                    break;
                case 2:
                    cout << A << "+" << B << "-" << C << "+" << D << "=7" << endl;
                    break;
                case 3:
                    cout << A << "-" << B << "+" << C << "+" << D << "=7" << endl;
                    break;
                case 4:
                    cout << A << "+" << B << "-" << C << "-" << D << "=7" << endl;
                    break;
                case 5:
                    cout << A << "-" << B << "-" << C << "+" << D << "=7" << endl;
                    break;
                case 6:
                    cout << A << "-" << B << "+" << C << "-" << D << "=7" << endl;
                    break;
                case 7:
                    cout << A << "-" << B << "-" << C << "-" << D << "=7" << endl;
                    break;
                default:
                    break;
            }
            return 0;
        }
    }
}