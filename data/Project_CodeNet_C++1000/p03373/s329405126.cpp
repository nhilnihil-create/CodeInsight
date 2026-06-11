#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int total;
    if(A + B <= 2 * C) {
        total = A * X + B * Y;
    } else {
        total = 2 * C * min(X, Y);
        if(X >= Y) {
            X -= Y;
            if(A <= 2 * C) {
                total += X * A;
            } else {
                total += X * 2 * C;
            }
        } else {
            Y -= X;
            if(B <= 2 * C) {
                total += Y * B;
            } else {
                total += Y * 2 * C;
            }
        }
    }
    cout << total << endl;

}