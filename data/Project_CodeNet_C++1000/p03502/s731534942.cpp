#include <bits/stdc++.h>
using namespace std;

int main() {
    int X; // 数字
    int Xsub;
    int Xsum = 0;
    int Harshad = 0;
    cin >> X;

    Xsub = X;
    
    while (Xsub > 0) {
        Xsum += Xsub % 10;
        Xsub /= 10;
    }

    Harshad = X % Xsum;
    if (Harshad == 0) {
        cout << "Yes" << endl;
    }
    else {
    cout << "No" << endl;
    }
    
}