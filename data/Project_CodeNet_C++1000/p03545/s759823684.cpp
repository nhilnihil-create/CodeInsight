#include <bits/stdc++.h>
using namespace std;

int main() {
    string ABCD;
    cin >> ABCD;
    int A, B, C, D, temp;
    temp = stoi(ABCD);
    A = temp / 1000;
    temp -= A * 1000;
    B = temp / 100;
    temp -= B * 100;
    C = temp / 10;
    temp -= C * 10;
    D = temp;
    //cout << "A " << A << ", B " << B << ", C " << C << ", D " << D << endl;

    vector<bool> ops(4, true);
    int ops_n = 0;
    bool phase1 = true, phase2 = false;

    while (true) {
        int sum = A;
        if (ops[0]) {
            sum += B;
        } else if (!ops[0]) {
            sum -= B;
        }

        if (ops[1]) {
            sum += C;
        } else if (!ops[1]) {
            sum -= C;
        }

        if (ops[2]) {
            sum += D;
        } else if (!ops[2]) {
            sum -= D;
        }

        if (sum == 7) {
            break;
        }

        /*cout << A;
        if (ops[0]) {
            cout << '+';
        } else {
            cout << '-';
        }
        
        cout << B;
        if (ops[1]) {
            cout << '+';
        } else {
            cout << '-';
        }

        cout << C;
        if (ops[2]) {
            cout << '+';
        } else {
            cout << '-';
        }
        cout << D << endl;*/

        if (phase1) {
            //cout << "Phase1 Roop : " << ops_n << endl;
            ops[ops_n] = false;
            if (ops_n > 0) {
                ops[ops_n - 1] = true;
            }
            if (ops_n == 3) {
                phase1 = false;
                phase2 = true;
                for (int i = 0; i < 3; i++) {
                    ops[i] = false;
                }
                ops_n = -1;
                //cout << "Phase1 finished;" << endl;
            }
            ops_n++;
        } else if (phase2) {
            ops[ops_n] = true;
            if (ops_n > 0) {
                ops[ops_n - 1] = false;
            } else if (ops_n == 3) {
                phase2 = false;
            }
            ops_n++;
        } else if (!phase1 && !phase2) {
            for (int i = 0; i < 3; i++) {
                ops[i] = false;
            }
        }
    }

    cout << A;
    if (ops[0]) {
        cout << '+';
    } else {
        cout << '-';
    }
    
    cout << B;
    if (ops[1]) {
        cout << '+';
    } else {
        cout << '-';
    }

    cout << C;
    if (ops[2]) {
        cout << '+';
    } else {
        cout << '-';
    }

    cout << D << "=7" << endl;

    return 0;
}